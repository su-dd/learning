#ifndef SHOP_H
#define SHOP_H
#include "SaleStrategyInterface.h"
class Shop
{
public:
    Shop():m_pStrategy(nullptr) {}
    ~Shop() {delete m_pStrategy;}
    void sell()
    {
        m_pStrategy->promotion();
    }

    void getStrategy(SaleStrategyInterface *strategy)
    {
        delete m_pStrategy;
        m_pStrategy = strategy;
    }

private:
    SaleStrategyInterface *m_pStrategy;
};
#endif // SHOP_H
