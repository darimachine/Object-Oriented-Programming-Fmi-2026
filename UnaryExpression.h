#pragma once
#include"IExpression.h"
#include<memory>

class UnaryExpression:public IExpression
{
protected:
	unique_ptr<IExpression> operand;

public:
	UnaryExpression(unique_ptr<IExpression> operand);
	bool isTrivial()const override;

	virtual ~UnaryExpression() = default;
};

