#ifndef SHOP_H
#define SHOP_H
#include "SaleStrategyInterface.h"
class Shop
{
public:
    Shop():m_pStrategy(nullptr) {}
    ~Shop() {m_pStrategy = nullptr;}
    void sell()
    {
        m_pStrategy->promotion();
    }

    void getStrategy(SaleStrategyInterface *strategy)
    {
        m_pStrategy = strategy;
    }

private:
    SaleStrategyInterface *m_pStrategy;
};
#endif // SHOP_H
