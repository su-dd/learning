#ifndef ICECREAMFACTORYINTERFACE_H
#define ICECREAMFACTORYINTERFACE_H
#include "IceCreamInterface.h"
// 冰淇淋工厂接口
class IceCreamFactoryInterface
{
public:
    virtual ~IceCreamFactoryInterface() {}
    virtual IceCreamInterface * createIceCream() = 0;
};
#endif // ICECREAMFACTORYINTERFACE_H
