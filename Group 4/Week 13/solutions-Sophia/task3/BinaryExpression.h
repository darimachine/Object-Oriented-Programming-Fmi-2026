#pragma once
#include "IExpression.h"
#include <memory>

class BinaryExpression : public IExpression 
{
protected:
    std::unique_ptr<IExpression> leftOperand;
    std::unique_ptr<IExpression> rightOperand; 
public:
    BinaryExpression(std::unique_ptr<IExpression>, std::unique_ptr<IExpression>);
    bool isBinary() const override;
};