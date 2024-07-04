#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Node.h"
#include <QList>
#include <QObject>
#include <QString>
#include <QJsonDocument>
class Document : public QObject
{
public:
    Document(QObject *parent = nullptr);
    ~Document();

    void init(QString info);
    QString save();


private:
    QJsonDocument m_oJsonDocument;
};

#endif // DOCUMENT_H
