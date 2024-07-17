#include "Page.h"

Page::Page(QObject *parent)
    : Node(parent)
{

} // constructor

Page::~Page()
{

} // destructor

void Page::initWithJson(QJsonObject &json)
{
}

QJsonObject Page::saveToJson()
{
    QJsonObject json;
    return json;
}

PageEditor::PageEditor()
{

}

PageEditor::~PageEditor()
{

}
