#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractScrollArea>
#include <QTimer>
#include <QTextLayout>
#include <memory>
#include "TextSeletion.h"
// 富文本组件
class RichText : public QAbstractScrollArea
{
    Q_OBJECT
public:
    RichText(QWidget *parent = nullptr);
    ~RichText();
public slots:
    void toggleCursor();

protected:
    void paintEvent(QPaintEvent *event) override;
    void scrollContentsBy(int dx, int dy) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    QString m_text;
    QFont m_font;
    QPoint m_offset;
    std::unique_ptr<QTextLayout> m_pTextLayout;
    std::unique_ptr<TextSeletion> m_pTextSeletion;
    std::unique_ptr<QTimer> m_pTimer;
    bool m_bShowCursor;
    int m_nCursorIndex;
};
#endif // WIDGET_H
