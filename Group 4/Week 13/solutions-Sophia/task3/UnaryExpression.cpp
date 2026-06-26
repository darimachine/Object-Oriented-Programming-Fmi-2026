#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(std::unique_ptr<IExpression> expr) : expr(std::move(expr))
{
}