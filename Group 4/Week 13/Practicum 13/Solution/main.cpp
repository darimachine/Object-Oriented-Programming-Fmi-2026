#include <iostream>

#include "AbsoluteExpression.h"
#include "AdditionExpression.h"
#include "DivisionExpression.h"
#include "ExpressionVault.h"
#include "MultiplicationExpression.h"
#include "NegativeExpression.h"
#include "NumberExpression.h"
#include "SubtractionExpression.h"

int main() {

    std::unique_ptr<IExpression> n1 = std::make_unique<NumberExpression>(NumberExpression(1));
    std::unique_ptr<IExpression> n2 = std::make_unique<NumberExpression>(NumberExpression(2));
    std::unique_ptr<IExpression> n3 = std::make_unique<NumberExpression>(NumberExpression(3));
    std::unique_ptr<IExpression> n4 = std::make_unique<NumberExpression>(NumberExpression(4));
    std::unique_ptr<IExpression> n5 = std::make_unique<NumberExpression>(NumberExpression(5));
    std::unique_ptr<IExpression> n6 = std::make_unique<NumberExpression>(NumberExpression(6));

    std::unique_ptr<IExpression> a12 = std::make_unique<AdditionExpression>(AdditionExpression(n1, n2));
    std::unique_ptr<IExpression> s24 = std::make_unique<SubtractionExpression>(SubtractionExpression(n2, n4));
    std::unique_ptr<IExpression> m53 = std::make_unique<MultiplicationExpression>(MultiplicationExpression(n5, n3));
    std::unique_ptr<IExpression> d62 = std::make_unique<DivisionExpression>(DivisionExpression(n6, n2));

    std::unique_ptr<IExpression> task1 = std::make_unique<AdditionExpression>(AdditionExpression(a12, s24));
    std::unique_ptr<IExpression> task2 = std::make_unique<DivisionExpression>(DivisionExpression(m53, d62));
    std::unique_ptr<IExpression> task3 = std::make_unique<AbsoluteExpression>(AbsoluteExpression(s24));
    std::unique_ptr<IExpression> task4 = std::make_unique<NegativeExpression>(NegativeExpression(s24));
    std::unique_ptr<IExpression> task5 = std::make_unique<SubtractionExpression>(SubtractionExpression(task1, task2));

    std::unique_ptr<IExpression> finalTask = std::make_unique<MultiplicationExpression>(MultiplicationExpression(task5, task3));


    ExpressionVault vault;

    vault.addProblem(task1);
    vault.addProblem(task2);
    vault.addProblem(task3);
    vault.addProblem(task4);
    vault.addProblem(task5);
    vault.addProblem(finalTask);

    std::cout << "List of all problems:" << std::endl;
    vault.listAll(std::cout);
    std::cout << std::endl;

    std::cout << "Solutions to all problems:" << std::endl;
    vault.solveAll(std::cout);
    std::cout << std::endl;

    std::cout << "Removing simple problems..." << std::endl;
    vault.markInvalid();
    std::cout << std::endl;

    std::cout << "List of invalid problems(marked as used):" << std::endl;
    vault.listAllUsed(std::cout);
    std::cout << std::endl;

    std::cout << "Creating a test:" << std::endl;
    vault.makeTest(3, "Madura test", std::cout, std::cin);
    std::cout << std::endl;

    std::cout << "History of problems, used in tests:" << std::endl;
    vault.showHistory(std::cout);
    std::cout << std::endl;

    return 0;
}
