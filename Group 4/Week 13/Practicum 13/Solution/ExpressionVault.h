//
// Created by Boris Bozhilov on 5/29/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EXPRESSIONVAULT_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EXPRESSIONVAULT_H

#include <memory>
#include <vector>

#include "IExpression.h"


class ExpressionVault {

private:
    std::vector<std::unique_ptr<IExpression>> problems;

    // utils
    std::vector<bool> usedProblems;
    unsigned int countOfUnusedProblems = 0;
    std::vector<unsigned int> history;

public:

    void addProblem(const std::unique_ptr<IExpression>& problem);
    void makeTest(const unsigned int tasksCount, const std::string& testName,
        std::ostream& output, std::istream& input);
    void listAll(std::ostream& output) const;
    void listAllUsed(std::ostream& output) const;
    void listAllNotUsed(std::ostream& output) const;
    void solveAll(std::ostream& output) const;
    void markInvalid();
    void showHistory(std::ostream &output) const;

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EXPRESSIONVAULT_H
