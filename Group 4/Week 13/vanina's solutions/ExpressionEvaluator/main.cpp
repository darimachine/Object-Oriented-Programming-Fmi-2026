#include<iostream>

#include "AbsoluteExpression.h"
#include "BinaryExpression.h"
#include "ExpressionVault.h"
#include "NegativeExpression.h"
#include "NumberExpression.h"

int main() {
    ExpressionVault test;

    test.addExpression(std::make_unique<BinaryExpression>(
    std::make_unique<NumberExpression>(-5),
    std::make_unique<NumberExpression>(3),
    '-' ));

    test.addExpression(std::make_unique<BinaryExpression>(
        std::make_unique<NegativeExpression>(
            std::make_unique<AbsoluteExpression>(
                std::make_unique<NegativeExpression>(
                    std::make_unique<NumberExpression>(-3)
                )))
            ,
            std::make_unique<BinaryExpression>(
                std::make_unique<NumberExpression>(-10),
                    std::make_unique<NumberExpression>(5), '/'),
                    '+'));

    test.addExpression(std::make_unique<BinaryExpression>(
        std::make_unique<NumberExpression>(2),
        std::make_unique<NumberExpression>(3),
        '*'));

    test.addExpression(std::make_unique<NegativeExpression>(
        std::make_unique<NumberExpression> (1)));

    test.listAll();

    std::cout << "\n======== solves ========\n";
    test.solveAll();

    test.markInvalid();
    std::cout << "\n\n";
    test.listAll();

    test.makeTest(1, "test1.txt");
    std::cout << "first test is ready\n";

    test.makeTest(1, "test2.txt");
    std::cout << "second test is ready\n";

    std::cout << "\n";
    std::cout << "======== used =========\n";
    test.listAllUsed();

    std::cout << "\n";
    std::cout << "======== not used =========\n";
    test.listAllNotUsed();

    return 0;

}
