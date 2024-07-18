#include "Paragraph.h"

ParagraphNode::ParagraphNode(QObject *parent)
    : Node(parent)
{
}

ParagraphNode::~ParagraphNode()
{
}

void ParagraphNode::initWithJson(QJsonObject &object)
{
    QJsonObject oDataObject = object.value(c_sEditor_Key_data).toObject();
    m_oNodeSharedPtr = NodeFactory::instance().createNode(sType, oDataObject);
}

QJsonObject ParagraphNode::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sEditor_Key_type, c_sEditor_node_type_paragraph);
    oObject.insert(c_sEditor_Key_data, m_oNodeSharedPtr->saveToJson());
    return oObject;
}

NodeEditorPtr ParagraphNode::createEditor(QWidget *parent)
{
    return new ParagraphEditor(this, parent);
}

ParagraphEditor::ParagraphEditor(Node *node, QWidget *parent)
    : NodeEditor(node, parent)
{

}
