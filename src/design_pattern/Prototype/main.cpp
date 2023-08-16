#include "IceCreamInterface.h"
#include "StrawberryIceCreamImpl.hpp"
#include "VanillaIceCreamImpl.hpp"

int main(int argc, char *argv[])
{
    // 买个草莓味的冰淇淋
    IceCreamInterface *pIceCreamPrototype1 = new StrawberryIceCreamImpl();
    // 买个香草味的冰淇淋
    IceCreamInterface *pIceCreamPrototype2 = new VanillaIceCreamImpl();


    // 克隆
    IceCreamInterface *pClone = pIceCreamPrototype1->clone();
    pClone->taste();
    delete pClone;

    pClone = pIceCreamPrototype2->clone();
    pClone->taste();
    delete pClone;

    delete pIceCreamPrototype1;
    delete pIceCreamPrototype2;
    return 0;
}
