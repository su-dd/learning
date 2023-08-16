#ifndef ICECREAM_HALFFAREIMPL_H
#define ICECREAM_HALFFAREIMPL_H
#include "SaleStrategyInterface.h"
#include <iostream>
class IceCream_halfFareImpl : public SaleStrategyInterface
{
public:
    virtual void promotion() override
    {
        std::string str = "冰淇淋半价！";
        std::cout << str << std::endl;
    }
};
#endif // ICECREAM_HALFFAREIMPL_H
