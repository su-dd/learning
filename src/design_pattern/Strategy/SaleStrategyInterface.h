#ifndef SALESTRATEGYINTERFACE_H
#define SALESTRATEGYINTERFACE_H
class SaleStrategyInterface
{
public:
    virtual ~SaleStrategyInterface() {}
    virtual void promotion() = 0;
};
#endif // SALESTRATEGYINTERFACE_H
