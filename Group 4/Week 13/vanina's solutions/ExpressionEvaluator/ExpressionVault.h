#ifndef EXPRESSIONEVALUATOR_EXPRESSIONVAULT_H
#define EXPRESSIONEVALUATOR_EXPRESSIONVAULT_H

#include <memory>
#include <vector>

#include "IExpression.h"

class ExpressionVault {
    std::vector<std::unique_ptr<IExpression>> expressions;
    std::vector<bool> isInAnyTest;
    std::vector<double> solves;
    std::vector<std::string> types;

public:
    void addExpression(std::unique_ptr<IExpression> expr);

    void makeTest(unsigned tasksCount, const std::string& testName);
    void listAll() const;
    void listAllUsed() const;
    void listAllNotUsed() const;

    void solveAll() const;

    void markInvalid();
};


#endif //EXPRESSIONEVALUATOR_EXPRESSIONVAULT_H