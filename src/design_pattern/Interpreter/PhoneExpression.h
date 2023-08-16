#ifndef PhoneExpressiosn_H
#define PhoneExpressiosn_H
#include "AbstractExpression.h"

class PhoneExpression : public AbstractExpression
{
public:
	PhoneExpression(AbstractExpression* expr)
		: m_Expr(expr) 
	{
	}

	virtual ~PhoneExpression()
	{
		delete m_Expr;
	}

	virtual string interprete(Context& ctx) override
	{
		return "联系方式：" + m_Expr->interprete(ctx);
	}
private:
	AbstractExpression* m_Expr;
};
#endif // PhoneExpressiosn_H