#ifndef CHIPS_FREEIMPL_H
#define CHIPS_FREEIMPL_H
#include "SaleStrategyInterface.h"
#include <iostream>

class Chips_freeImpl : public SaleStrategyInterface
{
public:
    virtual void promotion() override
    {
        std::cout << "薯条免费！" << std::endl;
    }
};
#endif // CHIPS_FREEIMPL_H
