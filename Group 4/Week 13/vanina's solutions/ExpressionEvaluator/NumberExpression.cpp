#include "NumberExpression.h"

NumberExpression::NumberExpression(double value) : value(value) {
}

double NumberExpression::eval() const {
    return value;
}

std::string NumberExpression::toString() const {
    if (value < 0) {
        return "(" + std::to_string(value) + ")";
    }
    return std::to_string(value);
}

std::string NumberExpression::getType() const {
    return "NumberExpression";
}
