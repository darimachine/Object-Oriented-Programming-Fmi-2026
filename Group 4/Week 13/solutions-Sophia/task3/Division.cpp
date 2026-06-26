#include "Division.h"
#include "DivisionByZeroException.hpp"

double Division::evaluate() const
{
    if (!rightOperand) {
        throw DivisionByZeroException();
    }
    return leftOperand->evaluate() / rightOperand->evaluate();
}

std::string Division::toString() const
{
    return leftOperand->toString() + ":" + rightOperand->toString();
}

std::unique_ptr<IExpression> Division::clone() const
{
    return std::make_unique<Division>(*this);
}
