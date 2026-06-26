#ifndef EXPRESSIONEVALUATOR_NEGATIVEEXPRESSION_H
#define EXPRESSIONEVALUATOR_NEGATIVEEXPRESSION_H

#include "UnaryExpression.h"

class NegativeExpression : public UnaryExpression {
public:
    explicit NegativeExpression(std::unique_ptr<IExpression> expr);

    double eval() const override;
    std::string toString() const override;

    std::string getType() const override;
};


#endif //EXPRESSIONEVALUATOR_NEGATIVEEXPRESSION_H