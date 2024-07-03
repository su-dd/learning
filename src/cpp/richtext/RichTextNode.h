#ifndef RICHTEXTNODE_H
#define RICHTEXTNODE_H

#include "Node.h"
#include <QTextLayout>
#include <QString>

class RichTextNode : public Node
{
    Q_OBJECT
public:
    explicit RichTextNode(QFont font, QObject *parent = nullptr);

    virtual fillInfo(QJsonObject object);
    virtual QJsonObject saveInfo();

    const QFont &defaultFont() const;
    const QString &text() const;
    QList<QTextLayout::FormatRange> getFormatRange();

    void insert();
    void remove();
private:
    QFont m_oDefaultfont;
    QString m_sText;
    std::unique_ptr<TextSeletion> m_pTextSeletion;
    QList<QTextLayout::FormatRange> m_oFormatRange;
    int m_nCursorIndex;
    bool m_nIsActivating;
};

#endif // RICHTEXTNODE_H
