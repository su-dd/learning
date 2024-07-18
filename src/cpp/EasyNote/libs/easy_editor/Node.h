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
#include <QPointer>
#include <QList>
#include "EditorConst.h"

class Node;
class NodeEditor;

using NodeSharedPtr = std::shared_ptr<Node>;
using NodeSharedPtrList = QList<NodeSharedPtr>;

using NodePtr = QPointer<Node>;
using NodePtrList = QList<NodeEditorPtr>;

using NodeEditorPtr = QPointer<NodeEditor>;
using NodeEditorPtrList = QList<NodeEditorPtr>;

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);
    virtual ~Node();

    NodeEditorPtr getEditor(QWidget *parent);
public:
    virtual void initWithJson(QJsonObject &object);
    virtual QJsonObject saveToJson();
    virtual NodeEditorPtr createEditor(QWidget *parent);

private:
    NodeEditorPtr m_pEditorPtr;
};

class NodeEditor : public QWidget
{
public:
    explicit NodeEditor(Node* node, QWidget *parent = nullptr);
    virtual ~NodeEditor();
protected:
    NodePtr m_oNodePtr;
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
                []() -> NodeSharedPtr
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
    NodeSharedPtr createNode(QString key, QJsonObject &object);

private:
    // 类的构造函数注册表
    std::map<std::string, std::function<std::shared_ptr<Node>()>> m_oFactoryRegistry;
};

// 定义宏用于注册类到工厂
#define REGISTER_NODE(ClassName, key) static NodeFactory::FactoryRegistrar<ClassName> ClassName##_FactoryRegistrar(key)

#endif // NODE_H
