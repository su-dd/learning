#include <iostream>

#include "Component.h"
#include "Composite.h"
#include "Leaf.h"

int main(int argc, char* argv[])
{
	Composite oComposite("厂家");
	Composite oComposite1("代理商");
	Composite oComposite2("零售商1");
	Composite oComposite3("零售商2");
	Leaf oLeaf1("顾客小王");
	Leaf oLeaf2("顾客小李");

	oComposite.add(&oComposite1);
	oComposite1.add(&oComposite2);
	oComposite1.add(&oComposite3);
	oComposite2.add(&oLeaf1);
	oComposite3.add(&oLeaf2);

	oComposite.buy(2);
	return 0;
}