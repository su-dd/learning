#ifndef NODE_H
#define NODE_H

#include <memory>
#include <QObject>
#include <QJsonObject>
#include <QFrame>
#include <functional>
#include <map>
#include <string>
#include <memory>
#include <QJsonObject>

class Node : public QObject
{
public:
    explicit Node(QObject *parent = nullptr)
        : QObject(parent)
    {
    }
    virtual ~Node() {}

    virtual void init(QJsonObject object) {}
    virtual QJsonObject toInfo() { return QJsonObject(); }
};

class NodeEditor : public QFrame
{
public:
    explicit NodeEditor(QWidget *parent = nullptr)
        : QFrame(parent)
    {
    }
    virtual ~NodeEditor()
    {
    }
};

using NodePtr = std::shared_ptr<Node>;

class NodeFactory
{
public:
    // 注册类的构造函数到工厂
    template <typename T>
    struct FactoryRegistrar
    {
        FactoryRegistrar(const std::string &key)
        {
            NodeFactory::instance().m_oFactoryRegistry.emplace(
                key,
                []() -> NodePtr
                {
                    return std::make_shared<T>();
                });
        }
    };

public:
    static NodeFactory &instance()
    {
        static NodeFactory instance;
        return instance;
    }

    NodePtr createShape(QString info, QJsonObject object)
    {
        QString sKey = info.split("|").at(0);
        auto it = m_oFactoryRegistry.find(sKey.toStdString());
        if (it != m_oFactoryRegistry.end())
        {
            auto result = it->second();
            result->init(object);
            return result;
        }
        return nullptr;
    }

private:
    // 类的构造函数注册表
    std::map<std::string, std::function<std::shared_ptr<Node>()>> m_oFactoryRegistry;
};

// 定义宏用于注册类到工厂
#define REGISTER_NODE(ClassName, key) static NodeFactory::FactoryRegistrar<ClassName> ClassName##_FactoryRegistrar(key)

#endif // NODE_H
