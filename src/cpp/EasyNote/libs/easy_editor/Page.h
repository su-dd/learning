#ifndef PAGE_H
#define PAGE_H
#include <QObject>
#include <QFrame>
#include "Node.h"
#include <QJsonObject>

class Page : public Node
{
    Q_OBJECT
public:
    Page(QObject *parent = 0);
    ~Page();
public:
    void initWithJson(QJsonObject &object) override;
    QJsonObject saveToJson() override;
    NodeEditorPtr createEditor(QWidget *parent) override;

private:
    NodeSharedPtrList m_oNodeSharedPtrList;
};

class PageEditor : public NodeEditor
{
    Q_OBJECT
public:
    PageEditor(Node* node, QWidget *parent = nullptr);
    ~PageEditor();
};

#endif /* PAGE_H */
