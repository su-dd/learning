#ifndef DOCUMENTEDITOR_H
#define DOCUMENTEDITOR_H

#include <QWidget>

class DocumentEditor : public QWidget
{
public:
    DocumentEditor(QWidget* parent = nullptr);
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // DOCUMENTEDITOR_H
