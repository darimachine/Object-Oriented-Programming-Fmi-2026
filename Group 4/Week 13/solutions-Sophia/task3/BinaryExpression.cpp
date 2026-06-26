#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(std::unique_ptr<IExpression> left, std::unique_ptr<IExpression> right)
    : leftOperand(std::move(left)), rightOperand(std::move(right))
{
}

bool BinaryExpression::isBinary() const
{
    return true;
}
