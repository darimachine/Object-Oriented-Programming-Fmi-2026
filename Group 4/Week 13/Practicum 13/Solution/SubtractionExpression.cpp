//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "SubtractionExpression.h"

double SubtractionExpression::evaluate() const {

    return expression1->evaluate() - expression2->evaluate();
}

std::unique_ptr<IExpression> SubtractionExpression::clone() const {

    return std::make_unique<SubtractionExpression>(*this);
}