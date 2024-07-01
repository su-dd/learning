#include "widget.h"
#include <QRect>
#include <QSize>
#include <QPainter>
#include <QTextCursor>
#include <QTextDocument>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QAbstractScrollArea(parent), m_offset(100, 100), m_pTimer(new QTimer()), m_bShowCursor(true), m_pTextLayout(std::make_unique<QTextLayout>()), m_nCursor(-1)
{
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled);
    setMouseTracking(true);
    connect(m_pTimer, &QTimer::timeout, this, &Widget::toggleCursor);
    m_pTimer->start(500); // 闪烁间隔为500毫秒
    m_text = QStringLiteral("这是一个示例文本，它可能会很长，需要换行显示。");
    m_font.setFamily("JetBrains Mono");
    m_font.setPointSize(12);
    m_pTextLayout->setText(m_text);
    m_pTextLayout->setFont(m_font);
}

Widget::~Widget()
{
}

void Widget::toggleCursor()
{
    m_bShowCursor = !m_bShowCursor;
    viewport()->update(); // 触发重新绘制
}

void Widget::paintEvent(QPaintEvent *event)
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

    // 绘制文本
    m_pTextLayout->draw(&painter, QPoint(0, 0));
    if (m_bShowCursor && m_nCursor > -1)
    {
        m_pTextLayout->drawCursor(&painter, QPoint(0, 0), m_nCursor);
    }

    painter.restore();
    QAbstractScrollArea::paintEvent(event);
}

void Widget::scrollContentsBy(int dx, int dy)
{
    auto x = m_offset.x() + dx;
    auto y = m_offset.y() + dy;
    m_offset = QPoint(x, y);
    viewport()->update();
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    // 鼠标点击事件
    if (event->button() == Qt::LeftButton)
    {
        // 计算点击位置对应的字符位置
        QPointF pos = event->localPos();
        qDebug() << "pos mousePressEvent: " << pos;
        m_nCursor = -1;
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
                m_nCursor = line.xToCursor(x);
                break;
            }
        }
        viewport()->update(); // 更新显示
    }
}
