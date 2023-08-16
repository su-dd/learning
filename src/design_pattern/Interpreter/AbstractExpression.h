#ifndef AbstractExpression_H
#define AbstractExpression_H
#include "Context.h"
#include <string>

using namespace std;

class AbstractExpression
{
public:
	virtual ~AbstractExpression() {}
	virtual string interprete(Context &ctx) = 0;
};
#endif // AbstractExpression_H