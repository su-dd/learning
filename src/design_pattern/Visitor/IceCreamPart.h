#ifndef ICECREAMPART_H
#define ICECREAMPART_H

#include "Visitor.h"
class IceCreamPart
{
public:
	virtual ~IceCreamPart() {}
	virtual void accept(Visitor *visitor) = 0;
};

#endif // !ICECREAMPART_H
