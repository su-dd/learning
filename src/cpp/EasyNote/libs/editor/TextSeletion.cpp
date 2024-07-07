#include "TextSeletion.h"

TextSeletion::TextSeletion(int start, int end, QColor color)
    : m_nStart(start)
    , m_nEnd(end)
    , m_oColor(color)
{
}

TextSeletion::~TextSeletion() { }

bool TextSeletion::isVaild() { return m_nStart != m_nEnd; }

void TextSeletion::setStart(int n) { m_nStart = n; }

void TextSeletion::setEnd(int n) { m_nEnd = n; }

void TextSeletion::setColor(QColor color) { m_oColor = color; }

std::pair<int, int> TextSeletion::getSeletion()
{
    if (m_nStart > m_nEnd) {
        return std::make_pair(m_nEnd, m_nStart);
    }
    return std::make_pair(m_nStart, m_nEnd);
}

QColor TextSeletion::getColor() const { return m_oColor; }
