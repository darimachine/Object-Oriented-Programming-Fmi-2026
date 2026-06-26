//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NEGATIVEEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NEGATIVEEXPRESSION_H
#include "UnaryExpression.h"


class NegativeExpression : public UnaryExpression {

public:

    NegativeExpression() = default;
    explicit NegativeExpression(const std::unique_ptr<IExpression> &expression) : UnaryExpression(expression){}

    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] std::unique_ptr<IExpression> clone() const override;

    ~NegativeExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NEGATIVEEXPRESSION_H
