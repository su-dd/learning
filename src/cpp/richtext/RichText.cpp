#include "RichText.h"
#include <QRect>
#include <QSize>
#include <QPainter>
#include <QTextCursor>
#include <QTextDocument>
#include <QDebug>

RichText::RichText(QWidget *parent)
    : QAbstractScrollArea(parent)
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
    m_text = QStringLiteral("这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。这是一个示例文本，它可能会很长，需要换行显示。");
    m_font.setFamily("JetBrains Mono");
    m_font.setPointSize(12);
    m_pTextLayout->setText(m_text);
    m_pTextLayout->setFont(m_font);
}

RichText::~RichText()
{
}

void RichText::toggleCursor()
{
    m_bShowCursor = !m_bShowCursor;
    viewport()->update(); // 触发重新绘制
}

void RichText::paintEvent(QPaintEvent *event)
{
    QPainter painter(viewport());
    painter.save();
    painter.setFont(m_font);
    // 设置文本的绘制区域
    QRectF rect(10, 10, width() - 20, height() - 20);

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

    // 绘制文本
    m_pTextLayout->draw(&painter, QPoint(0, 0));
    // 绘制光标
    if (m_bShowCursor && m_nCursorIndex > -1)
    {
        m_pTextLayout->drawCursor(&painter, QPoint(0, 0), m_nCursorIndex);
    }

    painter.restore();
    QAbstractScrollArea::paintEvent(event);
}

void RichText::scrollContentsBy(int dx, int dy)
{
    auto x = m_offset.x() + dx;
    auto y = m_offset.y() + dy;
    m_offset = QPoint(x, y);
    viewport()->update();
}

void RichText::mousePressEvent(QMouseEvent *event)
{
    // 鼠标点击事件
    if (event->button() == Qt::LeftButton)
    {
        // 计算点击位置对应的字符位置
        QPointF pos = event->localPos();
        qDebug() << "pos mousePressEvent: " << pos;
        m_nCursorIndex = -1;
        for (int i = 0; i < m_pTextLayout->lineCount(); ++i)
        {
            QTextLine line = m_pTextLayout->lineAt(i);
            QRectF lineRect = line.rect();
            qDebug() << "line mousePressEvent: " << lineRect;
            // 检查鼠标点击是否在当前行内
            if (lineRect.contains(pos))
            {
                // 计算点击位置在行内的相对位置
                qreal x = pos.x() - lineRect.left();
                // 使用line的position方法找到光标位置
                m_nCursorIndex = line.xToCursor(x);
                break;
            }
        }
        viewport()->update(); // 更新显示
    }
}
