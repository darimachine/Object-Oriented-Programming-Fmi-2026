//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "DivisionExpression.h"

double DivisionExpression::evaluate() const {

    if (expression2->evaluate() < EPSILON)
        throw std::runtime_error("Can't divide by zero, second expression evaluates to 0");

    return expression1->evaluate() / expression2->evaluate();
}

std::unique_ptr<IExpression> DivisionExpression::clone() const {

    return std::make_unique<DivisionExpression>(*this);
}
