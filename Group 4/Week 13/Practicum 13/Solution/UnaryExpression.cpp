//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(const std::unique_ptr<IExpression> &expression) {

    if (expression == nullptr)
        throw std::invalid_argument("Cannot copy from empty expression");

    this->expression = expression->clone();
}

UnaryExpression::UnaryExpression(const UnaryExpression &other) {

    if (other.expression == nullptr)
        throw std::invalid_argument("Cannot copy from empty expression");

    this->expression = other.expression->clone();
}
