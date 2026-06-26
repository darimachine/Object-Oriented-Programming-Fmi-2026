#pragma once
#include "UnaryExpression.h"
#include <memory>

class AbsoluteExpression : public UnaryExpression
{
private: 
    std::unique_ptr<IExpression> expr;
public:
    double evaluate() const override;
    std::string toString() const override;
};