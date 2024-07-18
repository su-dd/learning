#include "Document.h"

Document::Document(QObject *parent)
    : Node(parent)
{
}

Document::~Document()
{
}

void Document::initWithJson(QString info)
{
    QJsonParseError oError;
    QJsonDocument oJsonDocument = QJsonDocument::fromJson(info.toUtf8(), &oError);
    if (oError.error != QJsonParseError::ParseError::NoError)
    {
        qDebug() << oError.errorString();
        return;
    }
    initWithJson(oJsonDocument);
}

void Document::initWithJson(QJsonObject &object)
{

}

QJsonObject Document::saveToJson()
{
    return QJsonObject();
}

NodeEditorPtr Document::getEditor()
{

}

DocumentEditor::DocumentEditor(QWidget *parent)
{

}

void DocumentEditor::mousePressEvent(QMouseEvent *event)
{

}

void DocumentEditor::mouseMoveEvent(QMouseEvent *event)
{

}
