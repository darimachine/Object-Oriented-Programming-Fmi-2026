#include "AbsoluteExpression.h"

double AbsoluteExpression::evaluate() const
{
    return std::abs(expr->evaluate());
}

std::string AbsoluteExpression::toString() const
{
    return "|" + expr->toString() + "|";
}