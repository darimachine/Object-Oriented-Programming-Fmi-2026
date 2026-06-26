//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
#include "BinaryExpression.h"


class MultiplicationExpression : public BinaryExpression {

public:

    MultiplicationExpression() = default;
    MultiplicationExpression(const std::unique_ptr<IExpression> &expression1,
        const std::unique_ptr<IExpression> &expression2)
        : BinaryExpression(expression1, expression2, '*'){}

    [[nodiscard]] double evaluate() const override;

    [[nodiscard]] std::unique_ptr<IExpression> clone() const override;

    ~MultiplicationExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MULTIPLICATIONEXPRESSION_H
