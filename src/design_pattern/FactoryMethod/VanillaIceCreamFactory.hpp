#ifndef VANILLAICECREAMFACTORY_H
#define VANILLAICECREAMFACTORY_H
#include "IceCreamFactoryInterface.h"
#include "VanillaIceCreamImpl.hpp"
// 香草冰淇淋工厂
class VanillaIceCreamFactory : public IceCreamFactoryInterface
{
public:
    VanillaIceCreamFactory() {}
    IceCreamInterface * createIceCream()
    {
        return new VanillaIceCreamImpl();
    }
};
#endif // VANILLAICECREAMFACTORY_H
