#ifndef WIDGET_H
#define WIDGET_H

#include "TextSeletion.h"
#include "Node.h"
#include <QAbstractScrollArea>
#include <QTextLayout>
#include <QTimer>
#include <memory>

class RichText : public Node
{
    Q_OBJECT
public:
    explicit RichText(QJsonObject object, QObject *parent = nullptr);

    virtual void fillInfo(QJsonObject object);
    virtual QJsonObject saveInfo();

    const QFont &defaultFont() const;
    const QString &text() const;
    QList<QTextLayout::FormatRange> getFormatRange();

    void insert();
    void remove();
private:
    QFont m_oDefaultfont;
    QString m_sText;
    // std::unique_ptr<TextSeletion> m_pTextSeletion;
    QList<QTextLayout::FormatRange> m_oFormatRange;
    int m_nCursorIndex;
    bool m_nIsActivating;
};

// 富文本组件
class RichTextFrame : public NodeEditor
{
    Q_OBJECT
public:
    RichTextFrame(QWidget* parent = nullptr);
    ~RichTextFrame();
public slots:
    void toggleCursor();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    int getTextIndexByPos(QPointF& pos);


private:
    QString m_text;
    QFont m_font;
    QPoint m_offset;
    std::unique_ptr<QTextLayout> m_pTextLayout;
    std::unique_ptr<TextSeletion> m_pTextSeletion;
    std::unique_ptr<QTimer> m_pTimer;
    int m_nCursorIndex;
    bool m_bShowCursor;
};
#endif // WIDGET_H
