#include "BinaryExpression.h"
#include<stdexcept>

BinaryExpression::BinaryExpression(unique_ptr<IExpression> left, 
	unique_ptr<IExpression> right, char op) :left(move(left)), right(move(right))
{
	if (op != '+' && op != '-' && op != '*' && op != '/')
	{
		throw invalid_argument("Ivalid operator.");
	}
	this->op = op;
}


double BinaryExpression::eval()const
{
	double l = left->eval();
	double r = right->eval();

	if (op == '+')
	{
		return l + r;
	}
	else if (op == '-')
	{
		return l - r;
	}
	else if (op == '*')
	{
		return l * r;
	}
	else
	{
		if (r == 0)
		{
			throw logic_error("Cannot divide by zero.");
		}
		return l / r;
	}
}

string BinaryExpression::toString()const
{
	return "(" + left->toString() + " " + op + " " + right->toString() + ")";
}

bool BinaryExpression::isTrivial()const
{
	return false;
}