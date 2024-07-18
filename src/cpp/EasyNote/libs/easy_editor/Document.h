#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Node.h"
#include <QList>
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QWidget>
#include <QPointer>

class Document : public Node
{
    Q_OBJECT
public:
    Document(QObject *parent = nullptr);
    ~Document();
    void initWithJson(QString info);
public:
    void initWithJson(QJsonObject &object) override;
    QJsonObject saveToJson() override;
    NodeEditorPtr createEditor(QWidget *parent) override;
private:
    NodeSharedPtr m_oNodeSharedPtr;
};

class DocumentEditor : public NodeEditor
{
public:
    DocumentEditor(Node* node, QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
};

#endif // DOCUMENT_H
