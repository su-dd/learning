#ifndef Aggregate_H
#define Aggregate_H

#include "Iterator.h"

template<class Item>
class Aggregate
{
public:
	Aggregate() {}
	virtual ~Aggregate() {}
	virtual void pushData(Item item) {}
	virtual Iterator<Item>* createIterator() { return nullptr; }
	virtual Item* operator[](int index) { return nullptr; }
	virtual int getSize() { return 0; }
};

#endif // Aggregate_H