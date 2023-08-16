#ifndef ValueExpression_H
#define ValueExpression_H
#include "AbstractExpression.h"
#include "Context.h"
using namespace std;

class ValueExpression : public AbstractExpression
{
public:
	ValueExpression(string key) 
		: m_key(key)
	{
	}

	virtual string interprete(Context &ctx) override
	{
		return ctx.lookup(m_key);
	}
private:
	string m_key;
};
#endif // ValueExpression