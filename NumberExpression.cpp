#include "NumberExpression.h"

NumberExpression::NumberExpression(double value):value(value){}

double NumberExpression::eval()const
{
	return value;
}

string NumberExpression::toString()const
{
	return to_string(value);
}

bool NumberExpression::isTrivial()const
{
	return true;
}