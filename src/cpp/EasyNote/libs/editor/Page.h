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

    void initWithJson(QJsonObject &object) override;
    QJsonObject saveToJson() override;
};

class PageEditor : public QFrame
{
    Q_OBJECT
public:
    PageEditor();
    ~PageEditor();
};

#endif /* PAGE_H */
