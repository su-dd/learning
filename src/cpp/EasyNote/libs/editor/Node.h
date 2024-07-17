#ifndef NODE_H
#define NODE_H

#include <memory>
#include <QObject>
#include <QJsonObject>
#include <QWidget>
#include <functional>
#include <map>
#include <string>
#include <memory>
#include <QJsonObject>

class Node;
class NodeEditor;

using NodePtr = std::shared_ptr<Node>;
using NodeEditorPtr = std::shared_ptr<NodeEditor>;
using NodePtrList = std::vector<NodePtr>;
using NodeEditorPtrList = std::vector<NodeEditorPtr>;

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);
    virtual ~Node();

    virtual void initWithJson(QJsonObject &object) {}
    virtual QJsonObject saveToJson() { return QJsonObject(); }

protected:
    NodePtrList m_oNodes;
};

class NodeEditor : public QWidget
{
public:
    explicit NodeEditor(QWidget *parent = nullptr);
    virtual ~NodeEditor();
};

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
    NodePtr createNode(QString info, QJsonObject &object);

private:
    // 类的构造函数注册表
    std::map<std::string, std::function<std::shared_ptr<Node>()>> m_oFactoryRegistry;
};

// 定义宏用于注册类到工厂
#define REGISTER_NODE(ClassName, key) static NodeFactory::FactoryRegistrar<ClassName> ClassName##_FactoryRegistrar(key)

#endif // NODE_H
