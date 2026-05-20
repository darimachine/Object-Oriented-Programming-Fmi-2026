#ifndef EXPRESSIONEVALUATOR_UNARYEXPRESSION_H
#define EXPRESSIONEVALUATOR_UNARYEXPRESSION_H

#include <memory>

#include "IExpression.h"

class UnaryExpression : public IExpression {
protected:
    std::unique_ptr<IExpression> ex;
public:
    UnaryExpression() = default;
    explicit UnaryExpression(std::unique_ptr<IExpression> e);
};


#endif //EXPRESSIONEVALUATOR_UNARYEXPRESSION_H