#include "strawberryfactory.h"
#include "vanillafactory.h"
#include "icecream.h"

int main(int argc, char *argv[])
{
    StrawberryFactory oStrawberryFactory;
    IceCream oIceCream1 = oStrawberryFactory.createIceCream();
    oIceCream1.taste();


    VanillaFactory oVanillaFactory;
    IceCream oIceCream2 = oVanillaFactory.createIceCream();
    oIceCream2.taste();

    return 0;
}
