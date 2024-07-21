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
#include <QTimer>

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

    NodeSharedPtr m_pNodeSharedPtr;
};

class DocumentEditor : public NodeEditor
{
    Q_OBJECT
public:
    DocumentEditor(Node *node, QWidget *parent = nullptr);
    virtual ~DocumentEditor();
    void updateUi() override;
public slots:
    void toggleCursor();

private:
    std::unique_ptr<QTimer> m_pTimer;
    bool m_bShowCursor;
};

#endif // DOCUMENT_H
