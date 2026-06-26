//
// Created by Boris Bozhilov on 5/29/2026.
//

#include "ExpressionVault.h"
#include <iostream>
#include <fstream>

#include "AbsoluteExpression.h"
#include "BinaryExpression.h"
#include "NegativeExpression.h"
#include "UnaryExpression.h"

void ExpressionVault::addProblem(const std::unique_ptr<IExpression>& problem) {

    if (problem == nullptr) throw std::invalid_argument("Cannot add empty problems");

    problems.push_back(problem->clone());
    usedProblems.push_back(false);
    countOfUnusedProblems++;
}

void ExpressionVault::makeTest(const unsigned int tasksCount, const std::string &testName,
    std::ostream &output, std::istream &input) {

    if (countOfUnusedProblems == 0) throw std::runtime_error("There aren't any unused problems left");

    std::ofstream file(testName);

    const unsigned int problemsSize = problems.size();
    unsigned int index = problemsSize;

    for (unsigned int i = 0; i < tasksCount; i++) {

        std::print(output, "Please enter the problem's index(0 to {}): ", problemsSize - 1);
        input >> index;

        // Instead of throwing we loop around until the user chooses a valid index
        if (index >= problemsSize) {

            std::print(output, "Chosen index is out of bounds.\n");
            i--;
            continue;
        }
        if (usedProblems.at(index) == true) {

            std::print(output, "Index was already used.\n");
            i--;
            continue;
        }

        // we've found an unused problem
        usedProblems.at(index) = true;
        history.push_back(index);
        countOfUnusedProblems--;
        file << (i + 1) << ". " << problems.at(index)->toString() << std::endl;
    }

    file.close();
}

void ExpressionVault::listAll(std::ostream& output) const {

    const unsigned int size = problems.size();

    for (unsigned int i = 0; i < size; i++) {

        output << i << ". " << problems.at(i)->toString() << std::endl;
    }
}

void ExpressionVault::listAllUsed(std::ostream &output) const {

    const unsigned int size = problems.size();

    for (unsigned int i = 0; i < size; i++) {

        if (usedProblems.at(i) == false) continue;

        output << i << ". " << problems.at(i)->toString() << std::endl;
    }
}

void ExpressionVault::listAllNotUsed(std::ostream &output) const {

    const unsigned int size = problems.size();

    for (unsigned int i = 0; i < size; i++) {

        if (usedProblems.at(i) == true) continue;

        output << i << ". " << problems.at(i)->toString() << std::endl;
    }
}

void ExpressionVault::solveAll(std::ostream &output) const {

    const unsigned int size = problems.size();

    for (unsigned int i = 0; i < size; i++) {

        output << i << ". " << problems.at(i)->toString() << " = " << problems.at(i)->evaluate() << std::endl;
    }
}

void ExpressionVault::markInvalid() {

    const unsigned int size = problems.size();

    for (unsigned int i = 0; i < size; i++) {

        if (typeid(*(problems.at(i))) == typeid(UnaryExpression) ||
            typeid(*(problems.at(i))) == typeid(NegativeExpression) ||
            typeid(*(problems.at(i))) == typeid(AbsoluteExpression)) {
            usedProblems.at(i) = true;
            countOfUnusedProblems--;
        }
    }
}

void ExpressionVault::showHistory(std::ostream &output) const {

    if (history.size() > problems.size())
        throw std::runtime_error
        ("More problems are logged in history than the ones that exist(history.size() > problems.size())");

    if (history.empty()) {

        output << "None of the problems have been used in a test, yet" << std::endl;
        return;
    }

    const unsigned int historySize = history.size();

    for (unsigned int i = 0; i < historySize; i++) {

        output << history.at(i) << ". " << problems.at(history.at(i))->toString() << std::endl;
    }
}