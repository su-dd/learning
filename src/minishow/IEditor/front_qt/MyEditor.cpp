#include "MyEditor.h"

MyEditor::MyEditor(QWidget *parent)
     : QAbstractScrollArea(parent)
     , m_offset(0, 0)
{
    this->setFocusPolicy(Qt::StrongFocus);

}

MyEditor::~MyEditor()
{
}

void MyEditor::paintEvent(QPaintEvent *event)
{
    QPainter oPainter(viewport());

}

void MyEditor::scrollContentsBy(int dx, int dy)
{
    auto x = m_offset.x() + dx;
    auto y = m_offset.y() + dy;
    m_offset = QPoint(x, y);
    viewport()->update();
}

