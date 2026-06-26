//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "AdditionExpression.h"

double AdditionExpression::evaluate() const {

    return expression1->evaluate() + expression2->evaluate();
}

std::unique_ptr<IExpression> AdditionExpression::clone() const {

    return std::make_unique<AdditionExpression>(*this);
}
