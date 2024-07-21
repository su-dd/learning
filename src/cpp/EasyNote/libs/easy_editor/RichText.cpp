#include "RichText.h"

#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QTextCursor>
#include <QTextDocument>

RichTextNode::RichTextNode(QObject *parent)
    : Node(parent),
      m_offset(10, 10)
{
    m_oDefaultfont.setFamily("JetBrains Mono");
    m_oDefaultfont.setPointSize(12);
}

RichTextNode::~RichTextNode()
{
}

void RichTextNode::initWithJson(QJsonObject &object)
{
    QJsonObject oDataObject = object.value(c_sKey_data).toObject();
    m_sText = oDataObject.value(c_sKey_text).toString();
}

QJsonObject RichTextNode::saveToJson()
{
    QJsonObject oTextObject;
    oTextObject.insert(c_sKey_text, m_sText);

    QJsonObject oObject;
    oObject.insert(c_sKey_type, c_sNode_paragraph);
    oObject.insert(c_sKey_data, oTextObject);
    return oObject;
}

NodeEditorPtr RichTextNode::createEditor(QWidget *parent)
{
    return new RichTextEditor(this, parent);
}

QString &RichTextNode::getText()
{
    return m_sText;
}

QFont &RichTextNode::getFont()
{
    return m_oDefaultfont;
}

QPoint &RichTextNode::getOffset()
{
    return m_offset;
}

RichTextEditor::RichTextEditor(Node *node, QWidget *parent)
    : NodeEditor(node, parent),
      m_offset(10, 10),
      m_pTextLayout(std::make_unique<QTextLayout>()),
      m_pTextSeletion(std::make_unique<TextSeletion>(0, 0, QColor(Qt::red))),
      m_bShowCursor(true),
      m_nCursorIndex(-1)
{
    m_pRichTextNodeptr = qobject_cast<RichTextNode *>(m_pCurNodePtr.data());
}

RichTextEditor::~RichTextEditor()
{
}

void RichTextEditor::updateUi()
{
    m_pTextLayout->setText(m_pRichTextNodeptr->getText());
    m_pTextLayout->setFont(m_pRichTextNodeptr->getFont());
}

void RichTextEditor::toggleCursor()
{
    m_bShowCursor = !m_bShowCursor;
    update(); // 触发重新绘制
}

void RichTextEditor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.save();
    // painter.setFont(m_pRichTextNodeptr->getFont());
    // 设置文本的绘制区域
    QRectF rect(m_offset.x(), m_offset.y(), width() - 20, height() - 20);

    // 进行文本布局
    m_pTextLayout->beginLayout();
    while (true)
    {
        QTextLine line = m_pTextLayout->createLine();
        if (!line.isValid())
        {
            break; // 没有更多的文本行
        }
        line.setLineWidth(rect.width());
        line.setPosition(QPointF(rect.left(), rect.top()));

        rect.setY(line.position().y() + line.height());
    }
    m_pTextLayout->endLayout();

    // 绘制选择区域
    QList<QTextLayout::FormatRange> selections = QList<QTextLayout::FormatRange>();
    if (m_pTextSeletion->isVaild())
    {
        std::pair<int, int> oSeletion = m_pTextSeletion->getSeletion();
        QTextLayout::FormatRange oFormatRange;
        oFormatRange.start = oSeletion.first;
        oFormatRange.length = oSeletion.second - oSeletion.first;
        oFormatRange.format.setBackground(m_pTextSeletion->getColor());
        selections.append(oFormatRange);
    }

    // 绘制文本
    m_pTextLayout->draw(&painter, QPoint(0, 0), selections);
    // 绘制光标
    if (m_bShowCursor && m_nCursorIndex > -1)
    {
        m_pTextLayout->drawCursor(&painter, QPoint(0, 0), m_nCursorIndex);
    }

    painter.restore();
    NodeEditor::paintEvent(event);
}

void RichTextEditor::mousePressEvent(QMouseEvent *event)
{
    // 鼠标点击事件
    if (event->button() == Qt::LeftButton)
    {
        // 计算点击位置对应的字符位置
        QPointF pos = event->position();
        // 获取点击位置对应的字符位置
        m_nCursorIndex = getTextIndexByPos(pos);
        m_pTextSeletion->setStart(m_nCursorIndex);
        m_pTextSeletion->setEnd(m_nCursorIndex);
        updateUi(); // 更新显示
    }
    NodeEditor::mousePressEvent(event);
}

void RichTextEditor::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标移动事件
    if (event->buttons() & Qt::LeftButton)
    {
        // 计算移动位置对应的字符位置
        QPointF pos = event->position();
        // 获取移动位置对应的字符位置
        m_nCursorIndex = getTextIndexByPos(pos);
        if (m_nCursorIndex > -1)
            m_pTextSeletion->setEnd(m_nCursorIndex);
        updateUi(); // 更新显示
    }
    NodeEditor::mouseMoveEvent(event);
}

int RichTextEditor::getTextIndexByPos(QPointF &pos)
{
    int nTextIndex = -1;
    for (int i = 0; i < m_pTextLayout->lineCount(); ++i)
    {
        QTextLine line = m_pTextLayout->lineAt(i);
        QRectF lineRect = line.rect();

        // 第一行不在范围内，跳过
        if ((i == 0) && (lineRect.y() > pos.y()))
        {
            nTextIndex = 0;
            break;
        }

        // 最后一行不在范围内，跳过
        if ((i == m_pTextLayout->lineCount() - 1) && (lineRect.y() + lineRect.height() < pos.y()))
        {
            nTextIndex = m_pTextLayout->text().size();
            break;
        }

        // 检查鼠标点击是否在当前行内
        if (lineRect.contains(pos))
        {
            // 使用line的xToCursor方法找到光标位置
            nTextIndex = line.xToCursor(pos.x());
            break;
        }
    }
    return nTextIndex;
}
