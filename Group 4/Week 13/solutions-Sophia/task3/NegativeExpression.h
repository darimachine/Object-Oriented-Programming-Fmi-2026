#pragma once
#include "UnaryExpression.h"
#include <memory>

class NegativeExpression : public UnaryExpression
{
private: 
    std::unique_ptr<IExpression> expr;
public: 
    double evaluate() const override;
    std::string toString() const override;
    std::unique_ptr<IExpression> clone() const override;
    NegativeExpression(std::unique_ptr<IExpression> expr);
};