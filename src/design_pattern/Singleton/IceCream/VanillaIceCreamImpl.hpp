#ifndef VANILLAICECREAMIMPL_HPP
#define VANILLAICECREAMIMPL_HPP

#include <iostream>
#include "IceCreamInterface.h"

// 香草冰淇淋
class VanillaIceCreamImpl : public IceCreamInterface
{
public:
    virtual void taste() override
    {
        std::cout << "香草冰淇淋的味道！" << std::endl;
    }
};

#endif // VANILLAICECREAMIMPL_HPP
