#include "factoryproducer.h"
#include "ChipsInterface.h"
#include "IceCreamInterface.h"

int main(int argc, char *argv[])
{
    FactoryProducer oProducer;

    IceCreamInterface* pIceCream = nullptr;
    ChipsInterface* pChips = nullptr;

    FactoryInterface * pSet1 = oProducer.createSet(FactoryProducer::Set1);
    pIceCream = pSet1->createIceCream();
    pChips = pSet1->createChips();
    pIceCream->taste();
    pChips->size();

    delete pIceCream;
    delete pChips;
    delete pSet1;


    FactoryInterface * pSet2 = oProducer.createSet(FactoryProducer::Set2);
    pIceCream = pSet2->createIceCream();
    pChips = pSet2->createChips();
    pIceCream->taste();
    pChips->size();

    delete pIceCream;
    delete pChips;
    delete pSet2;

    return 0;
}
