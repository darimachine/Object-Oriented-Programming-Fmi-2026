#ifndef EXPRESSIONEVALUATOR_BINARYEXPRESSION_H
#define EXPRESSIONEVALUATOR_BINARYEXPRESSION_H
#include <memory>

#include "IExpression.h"


class BinaryExpression : public IExpression {
   std::unique_ptr<IExpression> lhs;
   std::unique_ptr<IExpression> rhs;
   char operation;

public:
   BinaryExpression(std::unique_ptr<IExpression> lhs, std::unique_ptr<IExpression> rhs,
      char operation);

   double eval() const override;
   std::string toString() const override;

   std::string getType() const override;
};


#endif //EXPRESSIONEVALUATOR_BINARYEXPRESSION_H