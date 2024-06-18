#ifndef MYEDITOR_H
#define MYEDITOR_H

#include <QWidget>

class MyEditor : public QWidget
{
    Q_OBJECT

public:
    MyEditor(QWidget *parent = nullptr);
    ~MyEditor();
};
#endif // MYEDITOR_H
