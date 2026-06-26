//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NUMBEREXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NUMBEREXPRESSION_H
#include "IExpression.h"


class NumberExpression : public IExpression{

protected:
    double value = 0;

public:

    NumberExpression() = default;
    NumberExpression(const double value) : value(value){}

    [[nodiscard]] double evaluate() const override;
    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] std::unique_ptr<IExpression> clone() const override;

    ~NumberExpression() override = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_NUMBEREXPRESSION_H
