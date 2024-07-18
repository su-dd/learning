#ifndef TEXTSELETION_H
#define TEXTSELETION_H

#include <QColor>
#include <utility>
class TextSeletion
{
public:
    TextSeletion(int start, int end, QColor oColor);
    ~TextSeletion();

    // 有效
    bool isVaild();
    void setStart(int n);
    void setEnd(int n);
    void setColor(QColor m_oColor);

    std::pair<int, int> getSeletion();
    QColor getColor() const;

private:
    int m_nStart;
    int m_nEnd;
    QColor m_oColor;
};
#endif // TEXTSELETION_H
