#ifndef WIDGET_H
#define WIDGET_H

#include "TextSeletion.h"
#include <QAbstractScrollArea>
#include <QTextLayout>
#include <QTimer>
#include <QWidget>
#include <memory>
// 富文本组件
class RichText : public QFrame
{
    Q_OBJECT
public:
    RichText(QWidget* parent = nullptr);
    ~RichText();
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
