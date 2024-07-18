#include "Node.h"

Node::Node(QObject *parent)
    : QObject(parent),
    m_pEditorPtr(nullptr)
{
}

Node::~Node()
{
    if (m_pEditorPtr)
    {
        delete m_pEditorPtr.data();
    }
}

NodeEditorPtr Node::getEditor(QWidget *parent)
{
    if (m_pEditorPtr)
    {
        m_pEditorPtr = createEditor(parent);
    }
    return m_pEditorPtr;
}

void Node::initWithJson(QJsonObject &object)
{
    // do nothing
}

QJsonObject Node::saveToJson()
{
    return QJsonObject();
}

NodeEditorPtr Node::createEditor(QWidget *parent)
{
    return new NodeEditor(this, parent);
}

NodeEditor::NodeEditor(Node *node, QWidget *parent)
    : QWidget(parent),
    m_oNodePtr(node)
{
}

NodeEditor::~NodeEditor()
{

}


NodeSharedPtr NodeFactory::createNode(QString key, QJsonObject &object)
{
    auto it = m_oFactoryRegistry.find(key.toStdString());
    if (it != m_oFactoryRegistry.end())
    {
        auto result = it->second();
        result->initWithJson(object);
        return result;
    }
    return nullptr;
}

