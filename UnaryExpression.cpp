#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(unique_ptr<IExpression> operand):
	operand(move(operand)){ }

bool UnaryExpression::isTrivial()const
{
	return true;
}