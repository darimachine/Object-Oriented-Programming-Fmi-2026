#pragma once
#include "IExpression.h"
#include <memory>

class UnaryExpression : public IExpression
{
private:
    std::unique_ptr<IExpression> expr;
};