#pragma once;
#include "BinaryExpression.h"

class Multiplication : public BinaryExpression
{
public:
    double evaluate() const override;
    std::string toString() const override;
    std::unique_ptr<IExpression> clone() const override;
};