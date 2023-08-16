#include <iostream>
#include "Director.h"
#include "ChocolateCakeBuilder.h"
#include "IceCreamCake.h"
using namespace std;

int main(int argc, char *argv[])
{
    ChocolateCakeBuilder oBuilder("可可蛋糕坯", "奶油冰淇淋");
    Director oDirector(&oBuilder);
    oDirector.makeCake();
    IceCreamCake *pCake = oBuilder.getProduct();
    pCake->taste();
    return 0;
}
