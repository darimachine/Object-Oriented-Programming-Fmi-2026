#pragma once
#include"UnaryExpression.h"

class NegativeExpression:public UnaryExpression
{
public:
	NegativeExpression(unique_ptr<IExpression> operand);

	double eval()const override;
	string toString()const override;
};

