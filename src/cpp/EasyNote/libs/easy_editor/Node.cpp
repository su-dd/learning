#include "Node.h"

Node::Node(QObject *parent)
    : QObject(parent)
{
}

Node::~Node()
{

}

void Node::initWithJson(QJsonObject &object)
{

}

QJsonObject Node::saveToJson()
{
    return QJsonObject();
}

NodeEditorPtr Node::getEditor()
{
    return NodeEditorPtr();
}


NodeEditor::NodeEditor(QWidget *parent)
    : QWidget(parent)
{
}

NodeEditor::~NodeEditor()
{

}


NodePtr NodeFactory::createNode(QString info, QJsonObject &object)
{
    QString sKey = info.split("|").at(0);
    auto it = m_oFactoryRegistry.find(sKey.toStdString());
    if (it != m_oFactoryRegistry.end())
    {
        auto result = it->second();
        result->initWithJson(object);
        return result;
    }
    return nullptr;
}

