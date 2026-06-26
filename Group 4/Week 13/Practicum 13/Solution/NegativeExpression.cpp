//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "NegativeExpression.h"

#include <format>

double NegativeExpression::evaluate() const {

    return -1 * expression->evaluate();
}

std::string NegativeExpression::toString() const {

    return "-(" + expression->toString() + ")";
}

std::unique_ptr<IExpression> NegativeExpression::clone() const {

    return std::make_unique<NegativeExpression>(*this);
}
