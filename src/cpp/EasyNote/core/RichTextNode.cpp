#include "RichTextNode.h"

RichTextNode::RichTextNode(QFont font, QObject *parent)
    : Node{parent}
{

}

void RichTextNode::fillInfo(QJsonObject object)
{

}

QJsonObject RichTextNode::saveInfo()
{
    return QJsonObject();
}

const QFont &RichTextNode::defaultFont() const
{
    return m_oDefaultfont;
}