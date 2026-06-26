//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IEXPRESSION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IEXPRESSION_H

#include <memory>
#include <string>

class IExpression {

public:

    [[nodiscard]] virtual double evaluate() const = 0;
    [[nodiscard]] virtual std::string toString() const = 0;

    [[nodiscard]] virtual std::unique_ptr<IExpression> clone() const = 0;

    virtual ~IExpression() = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_IEXPRESSION_H
