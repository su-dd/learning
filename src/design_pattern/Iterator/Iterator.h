#ifndef Iterator_H
#define Iterator_H
#include "Aggregate.h"
template<class Item>

class Iterator
{
public:
	Iterator() {}
	virtual ~Iterator() {}
	virtual void first() {}
	virtual void next() {}
	virtual Item* curItem() { return nullptr;  }
	virtual bool hasNext() { return false; }
};

#endif //Iterator_H