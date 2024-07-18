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
    QJsonObject oObject = oJsonDocument.object();
    initWithJson(oObject);
}

void Document::initWithJson(QJsonObject &object)
{
    QJsonObject oDocument = object.value(c_sEditor_Key_document).toObject();
    if (!oDocument.isEmpty())
    {
        QString sType = oDocument.value(c_sEditor_Key_type).toString();
        m_oNodeSharedPtr = NodeFactory::instance().createNode(sType, oDocument);
    }
}

QJsonObject Document::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sEditor_Key_document, m_oNodeSharedPtr->saveToJson());
    return oObject;
}

NodeEditorPtr Document::createEditor(QWidget *parent)
{
    return new DocumentEditor(this, parent);
}

DocumentEditor::DocumentEditor(Node *node, QWidget *parent)
    : NodeEditor(node, parent)
{

}

void DocumentEditor::mousePressEvent(QMouseEvent *event)
{

}

void DocumentEditor::mouseMoveEvent(QMouseEvent *event)
{

}
