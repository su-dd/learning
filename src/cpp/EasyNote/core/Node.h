#ifndef NODE_H
#define NODE_H

#include <QObject>
#include <QJsonObject>

class Node : public QObject
{
public:
    explicit Node(QObject *parent = nullptr);
    virtual ~Node();

    virtual void fillInfo(QJsonObject object) = 0;
    virtual QJsonObject saveInfo() = 0;
};

#endif // NODE_H
