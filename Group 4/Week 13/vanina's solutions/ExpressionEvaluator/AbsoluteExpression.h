#ifndef EXPRESSIONEVALUATOR_ABSOLUTEEXPRESSION_H
#define EXPRESSIONEVALUATOR_ABSOLUTEEXPRESSION_H

#include "UnaryExpression.h"

class AbsoluteExpression : public UnaryExpression {
public:
    explicit AbsoluteExpression(std::unique_ptr<IExpression> expr);

    double eval() const override;
    std::string toString() const override;

    std::string getType() const override;
};


#endif //EXPRESSIONEVALUATOR_ABSOLUTEEXPRESSION_H