#ifndef STRAWBERRYICECREAMIMPL_HPP
#define STRAWBERRYICECREAMIMPL_HPP

#include <iostream>
#include "IceCreamInterface.h"

// 草莓冰淇淋
class StrawberryIceCreamImpl : public IceCreamInterface
{
public:
    virtual void taste() override
    {
        std::cout << "草莓冰淇淋的味道！" << std::endl;
    }

    IceCreamInterface *clone()
    {
        return new StrawberryIceCreamImpl();
    }
};

#endif // STRAWBERRYICECREAMIMPL_HPP
