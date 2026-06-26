//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UNARYEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UNARYEXPRESSION_H
#include "IExpression.h"

#include <memory>


class UnaryExpression : public IExpression {

protected:

    std::unique_ptr<IExpression> expression;

public:

    UnaryExpression() = default;
    explicit UnaryExpression(const std::unique_ptr<IExpression> &expression);

    UnaryExpression(const UnaryExpression& other);

    [[nodiscard]] double evaluate() const override = 0;
    [[nodiscard]] std::string toString() const override = 0;

    [[nodiscard]] std::unique_ptr<IExpression> clone() const override = 0;

    virtual ~UnaryExpression() = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_UNARYEXPRESSION_H
