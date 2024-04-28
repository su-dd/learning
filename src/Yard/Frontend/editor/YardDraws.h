#ifndef YARDDRAWS_H
#define YARDDRAWS_H

#include <QObject>

class YardDraws : public QObject
{
    Q_OBJECT
public:
    explicit YardDraws(QObject *parent=Q_NULLPTR);
};

#endif // YARDDRAWS_H
