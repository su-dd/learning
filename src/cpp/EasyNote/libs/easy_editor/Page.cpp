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
    QJsonArray oArray = json.value(c_sEditor_Key_children).toArray();
    if (oArray.isEmpty())
    {
        return;
    }

    for (int index = 0; index < oArray.count(); index++)
    {
        QJsonObject oJsonObject = oArray.at(index).toObject();
        QString sType = oJsonObject.value(c_sEditor_Key_type).toString();
        m_oNodeSharedPtrList.push_back(NodeFactory::instance().createNode(sType, oJsonObject));
    }
}

QJsonObject Page::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sEditor_Key_type, c_sEditor_node_type_page);
    QJsonArray oChildArray;
    for (auto ptr : m_oNodeSharedPtrList)
    {
        oChildArray.push_back(ptr->saveToJson());
    }
    oObject.insert(c_sEditor_Key_children, oChildArray);

    return oObject;
}

NodeEditorPtr Page::createEditor(QWidget *parent)
{
    return new PageEditor(this, parent);
}

PageEditor::PageEditor(Node *node, QWidget *parent)
    :NodeEditor(node, parent)
{

}

PageEditor::~PageEditor()
{

}
