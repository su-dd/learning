#include "Shop.h"
#include "FlyweightFactory.h"

int main(int argc, char *argv[])
{
    Shop oShop;
    FlyweightFactory oFlyweightFactory;

    oShop.getStrategy(oFlyweightFactory.getStrategy(FlyweightFactory::Chips_free));
    oShop.sell();

    oShop.getStrategy(oFlyweightFactory.getStrategy(FlyweightFactory::IceCream_halfFare));
    oShop.sell();

    return 0;
}
