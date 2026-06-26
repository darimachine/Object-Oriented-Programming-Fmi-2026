//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(const std::unique_ptr<IExpression>& expression1,
    const std::unique_ptr<IExpression>& expression2,
    const char expressionOperator) : expressionOperator(expressionOperator) {

    if (expression1 == nullptr)
        throw std::invalid_argument("Can't use an empty pointer to set expression value in BinaryExpression");
    if (expression2 == nullptr)
        throw std::invalid_argument("Can't use an empty pointer to set expression value in BinaryExpression");

    this->expression1 = expression1->clone();
    this->expression2 = expression2->clone();

}

BinaryExpression::BinaryExpression(const BinaryExpression &other) : expressionOperator(other.expressionOperator) {

    if (other.expression1 == nullptr || other.expression2 == nullptr)
        throw std::invalid_argument("Cannot copy from empty expression(NegativeExpression copy constructor)");

    this->expression1 = other.expression1->clone();
    this->expression2 = other.expression2->clone();
}

std::string BinaryExpression::toString() const {

    return "(" + expression1->toString() + " " + expressionOperator + " " + expression2->toString() + ")";
}
