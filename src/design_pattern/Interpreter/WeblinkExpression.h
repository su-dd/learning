#ifndef WeblinkExpression_H
#define WeblinkExpression_H
#include "AbstractExpression.h"

class WeblinkExpression : public AbstractExpression
{
public:
	WeblinkExpression(AbstractExpression *expr)
		: m_Expr(expr)
	{
	}

	virtual ~WeblinkExpression()
	{
		delete m_Expr;
		m_Expr = nullptr;
	}

	virtual string interprete(Context& ctx) override
	{
		return "网址：" + m_Expr->interprete(ctx);
	}

private:
	AbstractExpression* m_Expr;
};
#endif // WeblinkExpression