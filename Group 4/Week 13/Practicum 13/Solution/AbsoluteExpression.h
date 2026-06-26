//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ABSOLUTEEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ABSOLUTEEXPRESSION_H
#include "UnaryExpression.h"


class AbsoluteExpression : public UnaryExpression{

public:

    AbsoluteExpression() = default;
    explicit AbsoluteExpression(const std::unique_ptr<IExpression> &expression) : UnaryExpression(expression){}

    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] std::unique_ptr<IExpression> clone() const override;

    ~AbsoluteExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ABSOLUTEEXPRESSION_H
