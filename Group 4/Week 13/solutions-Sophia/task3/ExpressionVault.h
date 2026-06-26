#pragma once
#include <vector>
#include <memory>
#include "IExpression.h"

class ExpressionVault
{
protected:
    std::vector<std::unique_ptr<IExpression>> expressions;
    std::vector<bool> usedTasks; 
    std::vector<size_t> history;
public:
    ExpressionVault() = default;
    void addExpression(std::vector<std::unique_ptr<IExpression>>&);
    void makeTest(unsigned tasksCount, const std::string& testName);
    void listAll() const;
    void listAllUsed() const;
    void listAllNotUsed() const;
    void solveAll() const;
    void markInvalid();
    void showHistory() const;
};
