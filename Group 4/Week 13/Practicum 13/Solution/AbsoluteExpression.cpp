//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "AbsoluteExpression.h"

double AbsoluteExpression::evaluate() const {

    return std::abs(expression->evaluate());
}

std::string AbsoluteExpression::toString() const {

    return "|" + expression->toString() + "|";
}

std::unique_ptr<IExpression> AbsoluteExpression::clone() const {

    return std::make_unique<AbsoluteExpression>(*this);
}
