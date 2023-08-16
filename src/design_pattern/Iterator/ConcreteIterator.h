#ifndef ConcreteIterator_H
#define ConcreteIterator_H

#include "Iterator.h"
#include "Aggregate.h"

template<class Item>

class ConcreteIterator : public Iterator<Item>
{
public:
	ConcreteIterator(Aggregate<Item> *a) : aggr(a), cur(0) {}
	virtual ~ConcreteIterator(){}

	virtual void first() override;
    virtual void next() override;
    virtual Item* curItem() override;
    virtual bool hasNext() override;
private:
	Aggregate<Item>* aggr;
	int cur;
};


template<class Item>
void ConcreteIterator<Item>::first()
{
    cur = 0;
}

template<class Item>
void ConcreteIterator<Item>::next()
{
    if (cur < aggr->getSize())
        cur++;
}

template<class Item>
Item* ConcreteIterator<Item>::curItem()
{
    if (cur < aggr->getSize())
    {
        return (*aggr)[cur];
    }
    else
    {
        return nullptr;
    }
}

template<class Item>
bool ConcreteIterator<Item>::hasNext()
{
    return cur >= aggr->getSize();
}
#endif // !ConcreteIterator_H