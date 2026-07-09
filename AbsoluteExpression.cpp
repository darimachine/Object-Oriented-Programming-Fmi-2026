#include "AbsoluteExpression.h"
#include<cmath>

AbsoluteExpression::AbsoluteExpression(unique_ptr<IExpression> operand):
	UnaryExpression(move(operand)){ }

double AbsoluteExpression::eval()const
{
	return abs(operand->eval());
}
string AbsoluteExpression::toString()const
{
	return "abs(" + operand->toString() + ")";
}