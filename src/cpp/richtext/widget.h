#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QAbstractScrollArea>
#include <QTimer>
#include <QTextLayout>
#include <memory>

class Widget : public QAbstractScrollArea
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void toggleCursor();
protected:
    void paintEvent(QPaintEvent* event) override;
    void scrollContentsBy(int dx, int dy) override;
    void mousePressEvent(QMouseEvent *event) override;
private:
    QPoint m_offset;
    std::unique_ptr<QTextLayout> m_pTextLayout;
    QTimer *m_pTimer;
    bool m_bShowCursor;
    QString m_text;
    QFont m_font;
    int m_nCursor;
};
#endif // WIDGET_H
