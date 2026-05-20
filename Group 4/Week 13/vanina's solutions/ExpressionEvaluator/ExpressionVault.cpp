#include "ExpressionVault.h"

#include "BinaryExpression.h"

#include<iostream>
#include<fstream>

void ExpressionVault::addExpression(std::unique_ptr<IExpression> expr) {
    solves.push_back(expr->eval());
    types.push_back(expr->getType());
    expressions.push_back(std::move(expr));
    isInAnyTest.push_back(false);
}

void ExpressionVault::makeTest(unsigned tasksCount, const std::string &testName) {
    size_t size = expressions.size();

    std::ofstream testFile(testName);
    std::cout << "Enter tasks number: \n";
    for (unsigned i = 0; i < tasksCount; i++) {
        int number;
        std::cin >> number;
        if (number < 0 || number >= size) {
            throw std::out_of_range("Tasks are only " + std::to_string(size));
        }
        if (isInAnyTest[number]) {
            throw std::logic_error("Task " + std::to_string(number) +
                " is already part of another test");
        }

        // std::ofstream testFile(testName, std::ios::app);
        // std::ofstream testFile(testName);
        if (!testFile.is_open()) {
            throw std::logic_error("Failed to open file " + testName);
        }

        testFile << i << ". ";
        testFile << expressions[number]->toString() << std::endl;
        isInAnyTest[number] = true;
        // testFile.close();
    }
    testFile.close();
}

void ExpressionVault::listAll() const {
    int index = 0;
    for (const auto& ex:expressions) {
        std::cout << std::to_string(index++) << ". " << ex->toString() << std::endl;
    }
}

void ExpressionVault::listAllUsed() const {
    int index = 0;
    for (const auto& ex:expressions) {
        if (isInAnyTest[index]) {
            std::cout << std::to_string(index) << ". " << ex->toString() << std::endl;
        }
        index++;
    }
}

void ExpressionVault::listAllNotUsed() const {
    int index = 0;
    for (const auto& ex:expressions) {
        if (!isInAnyTest[index]) {
            std::cout << std::to_string(index) << ". " << ex->toString() << std::endl;
        }
        index++;
    }
}

void ExpressionVault::solveAll() const {
    int index = 0;
    for (const auto& ex:expressions) {
        std::cout << std::to_string(index) << ". " << ex->toString()
        << " = " << solves[index++] << std::endl;
    }
}

void ExpressionVault::markInvalid() {
    int index = 0;
    for (const auto& ex:expressions) {
        if (types[index] != "BinaryExpression") {
            isInAnyTest[index] = true;
        }
        index++;
    }
}
