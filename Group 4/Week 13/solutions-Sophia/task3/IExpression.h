#pragma once
#include <string>
#include <memory>
class IExpression 
{
public:
    virtual double evaluate() const = 0;
    virtual std::string toString() const = 0;
    virtual std::unique_ptr<IExpression> clone() const = 0;
    bool isBinary() const;
    virtual ~IExpression() = default;
};