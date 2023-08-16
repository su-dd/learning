#include "IceCreamFactory.hpp"
#include "IceCreamInterface.h"

int main(int argc, char *argv[])
{
    // 买个草莓味的冰淇淋
    IceCreamInterface *pIceCream1 =
            IceCreamFactory::createIceCream(IceCreamFactory::StrawberryIceCream);
    pIceCream1->taste();

    // 买个香草味的冰淇淋
    IceCreamInterface *pIceCream2 =
            IceCreamFactory::createIceCream(IceCreamFactory::VanillaIceCream);
    pIceCream2->taste();

    delete pIceCream1;
    delete pIceCream2;
    return 0;
}
