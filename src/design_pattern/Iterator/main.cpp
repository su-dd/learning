#include <iostream>
#include "ConcreteAggregate.h"

int main(int argc, char* argv[])
{
    Aggregate<std::string>* aggr = new ConcreteAggregate<std::string>();
    aggr->pushData("草莓冰淇淋1");
    aggr->pushData("草莓冰淇淋2");
    aggr->pushData("香草冰淇淋2");
    Iterator<std::string>* it = aggr->createIterator();

    for (it->first(); !it->hasNext(); it->next())
    {
        std::cout << *it->curItem() << std::endl;
    }
    delete it;
    delete aggr;
    return 0;
}
