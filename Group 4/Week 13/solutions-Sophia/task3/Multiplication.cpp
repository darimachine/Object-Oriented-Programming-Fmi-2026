#include "Multiplication.h"

double Multiplication::evaluate() const
{
    return leftOperand->evaluate() * rightOperand->evaluate();
}

std::string Multiplication::toString() const
{
    return leftOperand->toString() + "*" + rightOperand->toString();
}

std::unique_ptr<IExpression> Multiplication::clone() const
{
    return std::make_unique<Multiplication>(*this);
}
