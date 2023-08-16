#ifndef StrawberryIceCreamImpl_HPP
#define StrawberryIceCreamImpl_HPP
#include "IceCreamInterface.h"
#include <iostream>

class StrawberryIceCreamImpl : public IceCreamInterface
{
public:
    virtual void taste() override
    {
        std::cout << "草莓味冰淇淋" << std::endl;
    }
};

#endif