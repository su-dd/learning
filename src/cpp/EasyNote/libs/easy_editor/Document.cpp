#include "Document.h"
#include <QBoxLayout>

Document::Document(QObject *parent)
    : Node(parent)
{
}

Document::~Document()
{
}

void Document::initWithJson(QString info)
{
    QJsonParseError oError;
    QJsonDocument oJsonDocument = QJsonDocument::fromJson(info.toUtf8(), &oError);
    if (oError.error != QJsonParseError::ParseError::NoError)
    {
        qDebug() << oError.errorString();
        return;
    }
    QJsonObject oObject = oJsonDocument.object();
    initWithJson(oObject);
}

void Document::initWithJson(QJsonObject &object)
{
    if (!object.isEmpty())
    {
        QJsonObject oDataObject = object.value(c_sKey_data).toObject();
        QString sType = oDataObject.value(c_sKey_type).toString();
        m_oChildNodePtrList.push_back(NodeFactory::instance().createNode(sType, oDataObject));
    }
}

QJsonObject Document::saveToJson()
{
    QJsonObject oObject;
    oObject.insert(c_sKey_type, c_sNode_document);
    oObject.insert(c_sKey_data, m_oChildNodePtrList[0]->saveToJson());
    return oObject;
}

NodeEditorPtr Document::createEditor(QWidget *parent)
{
    return new DocumentEditor(this, parent);
}

DocumentEditor::DocumentEditor(Node *node, QWidget *parent)
    : NodeEditor(node, parent),
      m_pTimer(std::make_unique<QTimer>()),
      m_bShowCursor(false)
{
    // 设置焦点策略为Qt::StrongFocus，表示编辑器可以获得键盘焦点
    setFocusPolicy(Qt::StrongFocus);
    // 启用输入法，允许在编辑器中使用输入法输入
    setAttribute(Qt::WA_InputMethodEnabled);
    // 开启鼠标追踪，以便在鼠标移动时发出mouseMoveEvent信号
    setMouseTracking(true);
    connect(m_pTimer.get(), &QTimer::timeout, this, &DocumentEditor::toggleCursor);
    m_pTimer->start(500); // 闪烁间隔为500毫秒
}

DocumentEditor::~DocumentEditor()
{
}

void DocumentEditor::toggleCursor()
{
    m_bShowCursor = !m_bShowCursor;
    update();
}

void DocumentEditor::updateUi()
{
}
