#include "ExpressionVault.h"
#include <iostream>
#include <fstream>
void ExpressionVault::addExpression(std::vector<std::unique_ptr<IExpression>> &expressionsToAdd)
{
    for (const auto& e : expressionsToAdd) {
        expressions.push_back(e->clone());
        usedTasks.push_back(false);
    }
}

void ExpressionVault::makeTest(unsigned tasksCount, const std::string &testName)
{
    std::ofstream file(testName);
    if (!file.is_open()) {
        std::cout << "unable to open file" << std::endl;
        return;
    }
    
    for (int i = 0; i < tasksCount; i++) {
        int index;
        std::cin >> index;

        if (index >= expressions.size()) {
            std::cout << "invalid index" << std::endl;
            i--;
            continue;
        }

        if (usedTasks[index]) {
            std::cout << "task, already used" << std::endl;
            i--;
            continue;
        }

        file << expressions[index]->toString() << "\n";
        usedTasks[index] = true;
        history.push_back(index);
    }
}

void ExpressionVault::listAll() const
{
    int index = 0;
    for (const auto& c : expressions) {
       std::cout << index++ << ". " << c->toString()<< std::endl;
    }
}

void ExpressionVault::listAllUsed() const
{
    for (int i = 0; i < expressions.size(); i++) {
        if (usedTasks[i]) {
            std::cout << i << ". " << expressions[i]->toString() << std::endl;
        }
    }
}

void ExpressionVault::listAllNotUsed() const
{
    for (int i = 0; i < expressions.size(); i++) {
        if (!usedTasks[i]) {
            std::cout << i << ". " << expressions[i]->toString() << std::endl;
        }
    }
}

void ExpressionVault::solveAll() const
{
    int index = 0;
    for (const auto& c : expressions) {
       std::cout << index++ << ". " << c->toString() << " = " << c->evaluate() << std::endl;
    }
}

void ExpressionVault::markInvalid()
{
    for (int i = 0; i , expressions.size(); i++) {
        if (!expressions[i]->isBinary()) {
            usedTasks[i] = true;
        }
    }
}

void ExpressionVault::showHistory() const
{
    for (const auto& index : history) {
        std::cout << index << ". " << expressions[index]->toString() << std::endl;
    }
}
