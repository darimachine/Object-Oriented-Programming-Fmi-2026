#pragma once
#include "BinaryExpression.h"
#include <memory>

class Subtraction : public BinaryExpression 
{
    double evaluate() const override;
    std::string toString() const override;
    std::unique_ptr<IExpression> clone() const override;
};