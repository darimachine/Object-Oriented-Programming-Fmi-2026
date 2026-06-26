#pragma once
#include "IExpression.h"
class NumberExpression : public IExpression
{
protected:
    double value;
public:
    double evaluate() const override;
    std::string toString() const override;
    std::unique_ptr<IExpression> clone() const override;
    NumberExpression(double value);
};