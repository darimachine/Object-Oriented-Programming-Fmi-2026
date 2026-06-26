#include "NegativeExpression.h"

NegativeExpression::NegativeExpression(std::unique_ptr<IExpression>
    expr) : UnaryExpression(std::move(expr)) {
}

double NegativeExpression::eval() const {
    return -(ex->eval());
}

std::string NegativeExpression::toString() const {
    return "-(" + ex->toString() + ")";
}

std::string NegativeExpression::getType() const {
    return "NegativeExpression";
}
