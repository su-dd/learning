#include <iostream>
#include <string>
#include "IceCreamCake.h"
using namespace std;

int main(int argc, char *argv[])
{
    IceCreamCake* pIceCreamCake = IceCreamCake::Builder("可可蛋糕坯", "奶油冰淇淋")
        .setChocolate("巧克力")
        .builer();
    pIceCreamCake->taste();
    return 0;
}
