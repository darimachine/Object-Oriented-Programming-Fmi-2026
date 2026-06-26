#include "Addition.h"

double Addition::evaluate() const
{
    return leftOperand->evaluate() + rightOperand->evaluate();
}

std::string Addition::toString() const
{
    return leftOperand->toString() + "+" + rightOperand->toString();
}

std::unique_ptr<IExpression> Addition::clone() const
{
    return std::make_unique<Addition>(*this);
}
