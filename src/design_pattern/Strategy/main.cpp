#include "Shop.h"
#include "IceCream_halfFareImpl.h"
#include "Chips_freeImpl.h"
#include <Windows.h>

int main(int argc, char *argv[])
{
    //SetConsoleOutputCP(CP_UTF8);
    Shop oShop;
    oShop.getStrategy(new Chips_freeImpl());
    oShop.sell();

    oShop.getStrategy(new IceCream_halfFareImpl());
    oShop.sell();

    return 0;
}
