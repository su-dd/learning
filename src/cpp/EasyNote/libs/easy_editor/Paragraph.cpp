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
    QJsonObject oDataObject = object.value(c_sKey_data).toObject();
    QString sType = oDataObject.value(c_sKey_type).toString();
    m_oChildNodePtrList.push_back(NodeFactory::instance().createNode(sType, oDataObject));
}

QJsonObject ParagraphNode::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sKey_type, c_sNode_paragraph);
    oObject.insert(c_sKey_data, m_oChildNodePtrList[0]->saveToJson());
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

ParagraphEditor::~ParagraphEditor()
{
}

void ParagraphEditor::updateUi()
{
}
