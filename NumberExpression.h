#pragma once
#include"IExpression.h"

class NumberExpression:public IExpression
{
private:
	double value;

public:
	NumberExpression(double value);

	double eval()const override;
	string toString()const override;
	bool isTrivial()const override;
};

