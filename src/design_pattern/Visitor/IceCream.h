#ifndef ICECREAM_H
#define ICECREAM_H
#include "Visitor.h"
#include "IceCreamPart.h"
#include <list>
using namespace std;
class IceCream
{
public:
	IceCream() {}
	~IceCream() 
	{
		for each (auto item in IceCreamPartList)
		{
			delete item;
		}
		IceCreamPartList.clear();
	}

	void accept(Visitor* vistor)
	{
		for each (auto item in IceCreamPartList)
		{
			item->accept(vistor);
		}
	}

	void add(IceCreamPart* part) 
	{
		IceCreamPartList.push_back(part);
	}

	void remove(IceCreamPart* part)
	{
		IceCreamPartList.remove(part);
	}

private:
	list<IceCreamPart*> IceCreamPartList;
};
#endif // !ICECREAM_H
