#pragma once
#include"IExpression.h"
#include<memory>

class BinaryExpression :public IExpression
{
private:
	unique_ptr<IExpression> left;
	unique_ptr<IExpression> right;
	char op;

public:
	BinaryExpression(unique_ptr<IExpression> left, unique_ptr<IExpression> right, char op);

	double eval()const override;
	string toString()const override;
	bool isTrivial()const override;
};


