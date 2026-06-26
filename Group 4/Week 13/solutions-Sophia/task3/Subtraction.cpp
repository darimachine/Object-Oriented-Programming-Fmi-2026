#include "Subtraction.h"

double Subtraction::evaluate() const
{
    return leftOperand->evaluate() - rightOperand->evaluate();
}

std::string Subtraction::toString() const
{
    return leftOperand->toString() + "-" + rightOperand->toString();
}

std::unique_ptr<IExpression> Subtraction::clone() const
{
    return std::make_unique<Subtraction>(*this);
}
