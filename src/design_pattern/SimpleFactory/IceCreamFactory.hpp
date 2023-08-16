#ifndef ICECREAMFACTORY_H
#define ICECREAMFACTORY_H

#include "IceCreamInterface.h"
#include "VanillaIceCreamImpl.hpp"
#include "StrawberryIceCreamImpl.hpp"

// 冰淇淋工厂
class IceCreamFactory
{
public:
    // 产品列表
    enum ProductList
    {
        StrawberryIceCream,
        VanillaIceCream
    };

public:
    static IceCreamInterface *createIceCream(ProductList productId)
    {
        IceCreamInterface *pProduct = nullptr;
        switch (productId)
        {
        case StrawberryIceCream:
            pProduct = new StrawberryIceCreamImpl();
            break;
        case VanillaIceCream:
            pProduct = new VanillaIceCreamImpl();
            break;
        default:
            break;
        }
        return pProduct;
    }
};

#endif // ICECREAMFACTORY_H
