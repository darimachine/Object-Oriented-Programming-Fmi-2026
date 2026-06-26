#pragma once
#include "BinaryExpression.h"
#include <memory>

class Addition : public BinaryExpression 
{
public:
    double evaluate() const override;
    std::string toString() const override;
    std::unique_ptr<IExpression> clone() const override;
};