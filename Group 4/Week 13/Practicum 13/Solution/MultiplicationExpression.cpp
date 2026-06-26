//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "MultiplicationExpression.h"

double MultiplicationExpression::evaluate() const {

    return expression1->evaluate() * expression2->evaluate();
}

std::unique_ptr<IExpression> MultiplicationExpression::clone() const {

    return std::make_unique<MultiplicationExpression>(*this);
}