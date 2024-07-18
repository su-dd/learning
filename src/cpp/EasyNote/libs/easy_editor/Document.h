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
    NodeEditorPtr getEditor() override;
private:
    NodePtr m_oNodePtr;
};

class DocumentEditor : public NodeEditor
{
public:
    DocumentEditor(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPointer<Document> m_pDocument;
    QList<QWidget *> m_oWidgetList;
};

#endif // DOCUMENT_H
