#ifndef EXPRESSIONEVALUATOR_IEXPRESSION_H
#define EXPRESSIONEVALUATOR_IEXPRESSION_H

#include<string>

class IExpression {
public:
    virtual double eval() const = 0;
    virtual std::string toString() const = 0;

    virtual std::string getType() const = 0;

    virtual ~IExpression() = default;
};


#endif //EXPRESSIONEVALUATOR_IEXPRESSION_H