#ifndef EXPRESSIONEVALUATOR_NUMBEREXPRESSION_H
#define EXPRESSIONEVALUATOR_NUMBEREXPRESSION_H

#include "IExpression.h"

class NumberExpression : public IExpression {
    double value;

public:
    explicit NumberExpression(double value);

    double eval() const override;
    std::string toString() const override;

    std::string getType() const override;
};


#endif //EXPRESSIONEVALUATOR_NUMBEREXPRESSION_H