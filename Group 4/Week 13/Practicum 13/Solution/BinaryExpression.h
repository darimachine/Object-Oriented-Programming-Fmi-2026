//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_BINARYEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_BINARYEXPRESSION_H
#include <memory>

#include "IExpression.h"


class BinaryExpression : public IExpression{

protected:

    std::unique_ptr<IExpression> expression1;
    std::unique_ptr<IExpression> expression2;
    char expressionOperator = 0;

public:

    BinaryExpression() = default;
    explicit BinaryExpression(const std::unique_ptr<IExpression>& expression1,
        const std::unique_ptr<IExpression>& expression2,
        const char expressionOperator);

    BinaryExpression(const BinaryExpression& other);

    [[nodiscard]] double evaluate() const override = 0;
    [[nodiscard]] std::string toString() const override;

    [[nodiscard]] virtual std::unique_ptr<IExpression> clone() const = 0;

    virtual ~BinaryExpression() = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_BINARYEXPRESSION_H
