#include "UnaryExpression.h"

UnaryExpression::UnaryExpression(std::unique_ptr<IExpression> e) {
    if (e == nullptr) {
        throw std::invalid_argument("null expression");
    }
    ex = std::move(e);
}
