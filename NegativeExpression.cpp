#include "NegativeExpression.h"

NegativeExpression::NegativeExpression(unique_ptr<IExpression> operand):
	UnaryExpression(move(operand)){ }

double NegativeExpression::eval()const
{
	return -operand->eval();
}

string NegativeExpression::toString()const
{
	return "(-" + operand->toString() + ")";
}