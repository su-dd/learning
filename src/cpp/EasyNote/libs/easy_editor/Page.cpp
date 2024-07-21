#include "Page.h"
#include <QJsonArray>

Page::Page(QObject *parent)
    : Node(parent)
{
}

Page::~Page()
{
}

void Page::initWithJson(QJsonObject &json)
{
    QJsonArray oArray = json.value(c_sKey_children).toArray();
    if (oArray.isEmpty())
    {
        return;
    }

    for (int index = 0; index < oArray.count(); index++)
    {
        QJsonObject oJsonObject = oArray.at(index).toObject();
        QString sType = oJsonObject.value(c_sKey_type).toString();
        m_oChildNodePtrList.push_back(NodeFactory::instance().createNode(sType, oJsonObject));
    }
}

QJsonObject Page::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sKey_type, c_sNode_page);
    QJsonArray oChildArray;
    for (auto ptr : m_oChildNodePtrList)
    {
        oChildArray.push_back(ptr->saveToJson());
    }
    oObject.insert(c_sKey_children, oChildArray);

    return oObject;
}

NodeEditorPtr Page::createEditor(QWidget *parent)
{
    return new PageEditor(this, parent);
}

PageEditor::PageEditor(Node *node, QWidget *parent)
    : NodeEditor(node, parent)
{
}

PageEditor::~PageEditor()
{
}
