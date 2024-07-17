#include "Document.h"

Document::Document(QObject *parent)
{
}

Document::~Document()
{
}

void Document::initWithJson(QString info)
{
    QJsonParseError oError;
    m_oJsonDocument = QJsonDocument::fromJson(info.toUtf8(), &oError);
    if (oError.error != NoError)
    {
        qDebug() << oError.errorString();
        return;
    }

}

QString Document::saveToJson()
{
    return nullptr;
}
