#ifndef ConcreateAggregate_H
#define ConcreateAggregate_H

#include "Aggregate.h"
#include <vector>
#include "ConcreteIterator.h"

template <class Item>
class ConcreteAggregate : public Aggregate<Item>
{
public:
    ConcreteAggregate() {};
    virtual ~ConcreteAggregate() {};

    virtual void pushData(Item item) override;
    virtual Iterator<Item>* createIterator() override;
    virtual Item* operator[](int index);
    virtual int getSize() override;
private:
    std::vector<Item> data;
};


template <class Item>
void ConcreteAggregate<Item>::pushData(Item item)
{
    data.push_back(item);
}

template <class Item>
Iterator<Item>* ConcreteAggregate<Item>::createIterator()
{
    return new ConcreteIterator<Item>(this);
}

template <class Item>
Item* ConcreteAggregate<Item>::operator[](int index)
{
    return &data.at(index);
}

template <class Item>
int ConcreteAggregate<Item>::getSize()
{
    return data.size();
}
#endif // !ConcreateAggregate_H

