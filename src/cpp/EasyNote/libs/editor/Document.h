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

class Document : public QObject
{
    Q_OBJECT
public:
    Document(QObject *parent = nullptr);
    ~Document();

    void initWithJson(QString info);
    QString saveToJson();

private:
    NodePtr m_oNodePtr;
};

class DocumentEditor : public QWidget
{
public:
    DocumentEditor(QWidget *parent = nullptr);
    void init(QString info);
    QString save();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPointer<Document> m_pDocument;
    QList<QWidget *> m_oWidgetList;
};

#endif // DOCUMENT_H
