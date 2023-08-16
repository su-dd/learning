#ifndef ICECREAM_HALFFAREIMPL_H
#define ICECREAM_HALFFAREIMPL_H
#include "SaleStrategyInterface.h"
#include <iostream>
class IceCream_halfFareImpl : public SaleStrategyInterface
{
public:
    virtual void promotion() override
    {
        std::cout << "冰淇淋半价！" << std::endl;
    }
};
#endif // ICECREAM_HALFFAREIMPL_H
