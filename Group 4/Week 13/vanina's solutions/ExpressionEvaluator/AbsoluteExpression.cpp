#include "AbsoluteExpression.h"

AbsoluteExpression::AbsoluteExpression(std::unique_ptr<IExpression>
    expr) : UnaryExpression(std::move(expr)) {
}

double AbsoluteExpression::eval() const {
    return abs(ex->eval());
}

std::string AbsoluteExpression::toString() const {
    return "|" + ex->toString() + "|";
}

std::string AbsoluteExpression::getType() const {
    return "AbsoluteExpression";
}
