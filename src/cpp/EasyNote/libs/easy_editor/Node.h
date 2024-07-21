#ifndef NODE_H
#define NODE_H
#include "EditorConst.h"

#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include <QObject>
#include <QWidget>
#include <QPointer>
#include <QBoxLayout>

#include <functional>
#include <memory>
#include <map>
#include <string>

class Node;
class NodeEditor;

using NodeSharedPtr = std::shared_ptr<Node>;
using NodeSharedPtrList = QList<NodeSharedPtr>;

using NodePtr = QPointer<Node>;
using NodePtrList = QList<NodePtr>;

using NodeEditorPtr = QPointer<NodeEditor>;
using NodeEditorPtrList = QList<NodeEditorPtr>;

class Node : public QObject
{
    Q_OBJECT
public:
    explicit Node(QObject *parent = nullptr);
    virtual ~Node();

    NodeEditorPtr getEditor(QWidget *parent);
    NodeSharedPtrList &getChildNodePtrList();

public:
    virtual void initWithJson(QJsonObject &object);
    virtual QJsonObject saveToJson();
    virtual NodeEditorPtr createEditor(QWidget *parent);

protected:
    // 节点编辑器
    NodeEditorPtr m_pEditorPtr;
    // 子节点
    NodeSharedPtrList m_oChildNodePtrList;
};

class NodeEditor : public QWidget
{
public:
    explicit NodeEditor(Node *node, QWidget *parent = nullptr);
    virtual ~NodeEditor();
    virtual void updateUi();

protected:
    virtual void initUi();
    virtual void createChildeEditor();
    virtual void doLayout();

protected:
    virtual void editorMousePress(QMouseEvent *event);
    virtual void editorMouseRelease(QMouseEvent *event);
    virtual void editorMouseDoubleClick(QMouseEvent *event);
    virtual void editorMouseMove(QMouseEvent *event);
    virtual void editorKeyPress(QKeyEvent *event);

protected:
    // 数据节点
    NodePtr m_pCurNodePtr;
    // 编辑器中包含的子节点编辑器
    NodeEditorPtrList m_oChildEditorPtrList;
    // 编辑器布局
    QVBoxLayout *m_pLayout;
    // 编辑器是否被选中
    bool m_bIsSelected = false;
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

    // 创建节点
    NodeSharedPtr createNode(QString key, QJsonObject &object)
    {
        auto it = m_oFactoryRegistry.find(key.toStdString());
        if (it != m_oFactoryRegistry.end())
        {
            auto result = it->second();
            result->initWithJson(object);
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
