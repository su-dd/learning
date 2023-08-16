#ifndef NutIceCreamDecorator_h
#define NutIceCreamDecorator_h

#include "IceCreamDecorator.h"
#include <iostream>

class NutIceCreamDecorator : public IceCreamDecorator
{
public:
    NutIceCreamDecorator(IceCreamInterface *iceCream)
        : IceCreamDecorator(iceCream)
    {
    }

    virtual void taste() override
    {
        std::cout << "带坚果的" << std::endl;
        IceCreamDecorator::taste();
    }
};

#endif