#include "NegativeExpression.h"

double NegativeExpression::evaluate() const
{
    return -1 * expr->evaluate();
}

std::string NegativeExpression::toString() const
{
    return "-" + expr->toString();
}

std::unique_ptr<IExpression> NegativeExpression::clone() const
{
    return std::make_unique<NegativeExpression>(*this);
}

NegativeExpression::NegativeExpression(std::unique_ptr <IExpression> expr) : expr(std::move(expr))
{
}