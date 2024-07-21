#ifndef RICHTEXT_H
#define RICHTEXT_H

#include "TextSeletion.h"
#include "Node.h"
#include <QAbstractScrollArea>
#include <QTextLayout>
#include <QTimer>
#include <memory>
#include <QColor>
#include <QUrl>

class RichTextNode : public Node
{
    Q_OBJECT

public:
    explicit RichTextNode(QObject *parent = nullptr);
    virtual ~RichTextNode();

public:
    void initWithJson(QJsonObject &object) override;
    QJsonObject saveToJson() override;
    NodeEditorPtr createEditor(QWidget *parent) override;

public:
    QString &getText();
    QFont &getFont();
    QPoint &getOffset();

private:
    QFont m_oDefaultfont;
    QString m_sText;
    QPoint m_offset;
    QList<QTextLayout::FormatRange> m_oFormatRange;
    int m_nCursorIndex;
    bool m_nIsActivating;
};
REGISTER_NODE(RichTextNode, c_sNode_richText.toStdString());

using RichTextNodePtr = QPointer<RichTextNode>;

// 富文本组件
class RichTextEditor : public NodeEditor
{
    Q_OBJECT
public:
    RichTextEditor(Node *node, QWidget *parent = nullptr);
    ~RichTextEditor();
    void updateUi() override;

public slots:
    void toggleCursor();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    int getTextIndexByPos(QPointF &pos);

private:
    RichTextNodePtr m_pRichTextNodeptr;
    QPoint m_offset;
    std::unique_ptr<QTextLayout> m_pTextLayout;
    std::unique_ptr<TextSeletion> m_pTextSeletion;
    int m_nCursorIndex;
    bool m_bShowCursor;
};
#endif // RICHTEXT_H
