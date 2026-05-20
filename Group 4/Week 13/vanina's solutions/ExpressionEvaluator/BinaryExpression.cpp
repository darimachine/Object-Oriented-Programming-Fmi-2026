#include "BinaryExpression.h"

static bool isValidOperation(char operation) {
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/');
}

BinaryExpression::BinaryExpression(std::unique_ptr<IExpression> lhs, std::unique_ptr<IExpression> rhs,
    char operation) {
    if (lhs == nullptr) {
        throw std::invalid_argument("left expression cannot be null");
    }
    if (rhs == nullptr) {
        throw std::invalid_argument("right expression cannot be null");
    }
    if (!isValidOperation(operation)) {
        throw std::invalid_argument("invalid operation (muss be +,-,*,/)");
    }

    this->lhs = std::move(lhs);
    this->rhs = std::move(rhs);
    this->operation = operation;
}

double BinaryExpression::eval() const {
    switch (operation) {
        case '+':
            return lhs->eval() + rhs->eval();
        case '-':
            return lhs->eval() - rhs->eval();
        case '*':
            return lhs->eval() * rhs->eval();
        case '/':
            return lhs->eval() / rhs->eval();
        default:
            throw std::invalid_argument("invalid operation (muss be +,-,*,/)");
    }
}

std::string BinaryExpression::toString() const {
    return lhs->toString() + " " + operation + " " + rhs->toString();
}

std::string BinaryExpression::getType() const {
    return "BinaryExpression";
}
