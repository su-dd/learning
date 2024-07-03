#include "RichTextNode.h"

RichTextNode::RichTextNode(QFont font, QObject *parent)
    : Node{parent}
{

}

RichTextNode::fillInfo(QJsonObject object)
{

}

QJsonObject RichTextNode::saveInfo()
{

}

const QFont &RichTextNode::defaultFont() const
{
    return m_oDefaultfont;
}
