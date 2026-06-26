#include "NumberExpression.h"

double NumberExpression::evaluate() const
{
    return value;
}

std::string NumberExpression::toString() const
{
    return std::to_string(value);
}

std::unique_ptr<IExpression> NumberExpression::clone() const
{
    return std::make_unique<NumberExpression>(*this);
}

NumberExpression::NumberExpression(double value) : value(value) 
{
}