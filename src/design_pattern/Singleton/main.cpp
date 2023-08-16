#include "LazySingletonFactoryFacade.hpp"
#include "EagerSingletonFactoryFacade.hpp"

#define LazySingleton

int main(int argc, char *argv[])
{
#ifdef LazySingleton
    // 懒汉单例1
    //IceCreamFactoryFacadeInterface *pFactoryFacade = LazySingletonFactoryFacade::getInstance_1();
    // 懒汉单例2
    IceCreamFactoryFacadeInterface *pFactoryFacade = LazySingletonFactoryFacade::getInstance_2();

    IceCreamInterface* pStrawberryIceCream = pFactoryFacade->createStrawberryIceCream();
    IceCreamInterface* pVanillaIceCream = pFactoryFacade->createVanillaIceCream();

    pStrawberryIceCream->taste();
    pVanillaIceCream->taste();

    delete pStrawberryIceCream;
    delete pVanillaIceCream;

    LazySingletonFactoryFacade::freeInstancel();
    pFactoryFacade = nullptr;

#else

    IceCreamFactoryFacadeInterface *pFactoryFacade = EagerSingletonFactoryFacade::getInstance();
    IceCreamInterface* pStrawberryIceCream = pFactoryFacade->createStrawberryIceCream();
    IceCreamInterface* pVanillaIceCream = pFactoryFacade->createVanillaIceCream();
    pStrawberryIceCream->taste();
    pVanillaIceCream->taste();
    delete pStrawberryIceCream;
    delete pVanillaIceCream;

    pFactoryFacade = nullptr;
#endif
    return 0;
}
