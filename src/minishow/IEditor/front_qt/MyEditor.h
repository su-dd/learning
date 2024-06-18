#ifndef MYEDITOR_H
#define MYEDITOR_H

#include <QWidget>
#include <QAbstractScrollArea>

class MyEditor : public QAbstractScrollArea
{
    Q_OBJECT

public:
    MyEditor(QWidget *parent = nullptr);
    ~MyEditor();

protected:
    void paintEvent(QPaintEvent *event) override;
    void scrollContentsBy(int dx, int dy) override;
private:
    QPoint m_offset;
};
#endif // MYEDITOR_H
