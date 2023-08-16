#ifndef ICECREAMFACTORYFACADEINTERFACE_H
#define ICECREAMFACTORYFACADEINTERFACE_H

#include "IceCreamInterface.h"
class IceCreamFactoryFacadeInterface
{
public:
    virtual ~IceCreamFactoryFacadeInterface() {}
public:
    virtual IceCreamInterface *createStrawberryIceCream() = 0;
    virtual IceCreamInterface *createVanillaIceCream() = 0;
};

#endif // ICECREAMFACTORYFACADEINTERFACE_H
