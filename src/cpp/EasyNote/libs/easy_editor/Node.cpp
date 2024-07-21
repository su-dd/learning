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

NodeSharedPtrList &Node::getChildNodePtrList()
{
    return m_oChildNodePtrList;
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
      m_pCurNodePtr(node),
      m_pLayout(new QVBoxLayout)
{
    m_pLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(m_pLayout);
    initUi();
}

NodeEditor::~NodeEditor()
{
}

void NodeEditor::updateUi()
{
}

void NodeEditor::editorMousePress(QMouseEvent *event)
{
}

void NodeEditor::editorMouseRelease(QMouseEvent *event)
{
}

void NodeEditor::editorMouseDoubleClick(QMouseEvent *event)
{
}

void NodeEditor::editorMouseMove(QMouseEvent *event)
{
}

void NodeEditor::editorKeyPress(QKeyEvent *event)
{
}

void NodeEditor::initUi()
{
    createChildeEditor();
    doLayout();
}

void NodeEditor::createChildeEditor()
{
    for (int i = 0; i < m_pCurNodePtr->getChildNodePtrList().size(); ++i)
    {
        m_oChildEditorPtrList.push_back(
            m_pCurNodePtr->getChildNodePtrList()[i]->createEditor(this));
    }
}

void NodeEditor::doLayout()
{
    for (int i = 0; i < m_oChildEditorPtrList.size(); ++i)
    {
        m_pLayout->addWidget(m_oChildEditorPtrList[i]);
    }
}
// end of file