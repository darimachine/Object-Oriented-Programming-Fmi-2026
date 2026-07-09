#pragma once
#include"UnaryExpression.h"

class AbsoluteExpression:public UnaryExpression
{
public:
	AbsoluteExpression(unique_ptr<IExpression> operand);

	double eval()const override;
	string toString()const override;
};

