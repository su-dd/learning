#include "DocumentEditor.h"
#include <QMouseEvent>

DocumentEditor::DocumentEditor(QWidget *parent)
    :QWidget(parent)
{

}

void DocumentEditor::mousePressEvent(QMouseEvent *event)
{
    // 鼠标点击事件
    if (event->button() == Qt::LeftButton) {
        // 计算点击位置对应的字符位置
        QPointF pos = event->position();
        update(); // 更新显示
    }
    QWidget::mousePressEvent(event);
}

void DocumentEditor::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标移动事件
    if (event->buttons() & Qt::LeftButton) {
        // 计算移动位置对应的字符位置
        QPointF pos = event->position();
        update(); // 更新显示
    }
    QWidget::mouseMoveEvent(event);
}
