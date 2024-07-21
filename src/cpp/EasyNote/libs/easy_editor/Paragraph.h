#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include "Node.h"
#include <QFrame>

class ParagraphNode : public Node
{
public:
    ParagraphNode(QObject *parent = nullptr);
    virtual ~ParagraphNode();

public:
    virtual void initWithJson(QJsonObject &object);
    virtual QJsonObject saveToJson();
    virtual NodeEditorPtr createEditor(QWidget *parent);
};
REGISTER_NODE(ParagraphNode, c_sNode_paragraph.toStdString());

class ParagraphEditor : public NodeEditor
{
public:
    ParagraphEditor(Node *node, QWidget *parent = nullptr);
    virtual ~ParagraphEditor();
    void updateUi() override;

private:
    NodeEditorPtr m_pEditorPtr;
};

#endif // PARAGRAPH_H
