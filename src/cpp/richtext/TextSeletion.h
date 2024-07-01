#ifndef __TEXTSELETION_H__
#define __TEXTSELETION_H__

#include <QColor>
#include <utility>
class TextSeletion {

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
#endif // __TEXTSELETION_H__