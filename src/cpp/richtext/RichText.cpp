#include "RichText.h"

#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QSize>
#include <QTextCursor>
#include <QTextDocument>

RichText::RichText(QWidget* parent)
    : QFrame(parent)
    , m_offset(10, 10)
    , m_pTextLayout(std::make_unique<QTextLayout>())
    , m_pTextSeletion(std::make_unique<TextSeletion>(0, 0, QColor(Qt::red)))
    , m_pTimer(std::make_unique<QTimer>())
    , m_bShowCursor(true)
    , m_nCursorIndex(-1)
{
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);
    setMouseTracking(true);
    connect(m_pTimer.get(), &QTimer::timeout, this, &RichText::toggleCursor);
    m_pTimer->start(500); // 闪烁间隔为500毫秒
    m_text = QStringLiteral(
        "这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很"
        "长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示"
        "例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。");
    m_font.setFamily("JetBrains Mono");
    m_font.setPointSize(12);
    m_pTextLayout->setText(m_text);
    m_pTextLayout->setFont(m_font);
}

RichText::~RichText() { }

void RichText::toggleCursor()
{
    m_bShowCursor = !m_bShowCursor;
    update(); // 触发重新绘制
}

void RichText::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.save();
    painter.setFont(m_font);
    // 设置文本的绘制区域
    QRectF rect(m_offset.x(), m_offset.y(), width() - 20, height() - 20);

    // 进行文本布局
    m_pTextLayout->beginLayout();
    while (true) {
        QTextLine line = m_pTextLayout->createLine();
        if (!line.isValid()) {
            break; // 没有更多的文本行
        }
        line.setLineWidth(rect.width());
        line.setPosition(QPointF(rect.left(), rect.top()));

        rect.setY(line.position().y() + line.height());
    }
    m_pTextLayout->endLayout();

    // 绘制选择区域
    QList<QTextLayout::FormatRange> selections = QList<QTextLayout::FormatRange>();
    if (m_pTextSeletion->isVaild()) {
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
    if (m_bShowCursor && m_nCursorIndex > -1) {
        m_pTextLayout->drawCursor(&painter, QPoint(0, 0), m_nCursorIndex);
    }

    painter.restore();
    QFrame::paintEvent(event);
}

void RichText::mousePressEvent(QMouseEvent* event)
{
    // 鼠标点击事件
    if (event->button() == Qt::LeftButton) {
        // 计算点击位置对应的字符位置
        QPointF pos = event->position();
        // 获取点击位置对应的字符位置
        m_nCursorIndex = getTextIndexByPos(pos);
        m_pTextSeletion->setStart(m_nCursorIndex);
        m_pTextSeletion->setEnd(m_nCursorIndex);
        update(); // 更新显示
    }
    QFrame::mousePressEvent(event);
}

void RichText::mouseMoveEvent(QMouseEvent* event)
{
    // 鼠标移动事件
    if (event->buttons() & Qt::LeftButton) {
        // 计算移动位置对应的字符位置
        QPointF pos = event->position();
        // 获取移动位置对应的字符位置
        m_nCursorIndex = getTextIndexByPos(pos);
        if (m_nCursorIndex > -1)
            m_pTextSeletion->setEnd(m_nCursorIndex);
        update(); // 更新显示
    }
    QFrame::mouseMoveEvent(event);
}

void RichText::mouseReleaseEvent(QMouseEvent* event)
{
    QFrame::mouseReleaseEvent(event);
}

void RichText::keyPressEvent(QKeyEvent* event)
{
    QFrame::keyPressEvent(event);
}

int RichText::getTextIndexByPos(QPointF& pos)
{
    int nTextIndex = -1;
    for (int i = 0; i < m_pTextLayout->lineCount(); ++i) {
        QTextLine line = m_pTextLayout->lineAt(i);
        QRectF lineRect = line.rect();

        // 第一行不在范围内，跳过
        if ((i == 0) && (lineRect.y() > pos.y())) {
            nTextIndex = 0;
            break;
        }

        // 最后一行不在范围内，跳过
        if ((i == m_pTextLayout->lineCount() - 1) && (lineRect.y() + lineRect.height() < pos.y())) {
            nTextIndex = m_pTextLayout->text().size();
            break;
        }

        // 检查鼠标点击是否在当前行内
        if (lineRect.contains(pos)) {
            // 使用line的xToCursor方法找到光标位置
            nTextIndex = line.xToCursor(pos.x());
            break;
        }
    }
    return nTextIndex;
}
