#ifndef PARAGRAPH_H
#define PARAGRAPH_H
#include "Node.h"
#include <QFrame>

class ParagraphNode : public Node
{
public:
    ParagraphNode(QObject *parent = nullptr);
};
REGISTER_NODE(ParagraphNode, "Paragraph");

class ParagraphEditor : public NodeEditor
{
public:
    ParagraphEditor();
};

#endif // PARAGRAPH_H
