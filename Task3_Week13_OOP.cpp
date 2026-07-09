#include <iostream>
#include "ExpressionVault.h"
#include "NumberExpression.h"
#include "NegativeExpression.h"
#include "AbsoluteExpression.h"
#include "BinaryExpression.h"

int main()
{
    ExpressionVault vault;

    vault.add(make_unique<NumberExpression>(5));
    vault.add(make_unique<NumberExpression>(-3));
    vault.add(make_unique<NegativeExpression>(make_unique<NumberExpression>(4)));
    vault.add(make_unique<AbsoluteExpression>(make_unique<NumberExpression>(-7)));
    vault.add(make_unique<BinaryExpression>(
        make_unique<NumberExpression>(3),
        make_unique<NumberExpression>(4),
        '+'));
    vault.add(make_unique<BinaryExpression>(
        make_unique<NumberExpression>(10),
        make_unique<NumberExpression>(2),
        '/'));
    vault.add(make_unique<BinaryExpression>(
        make_unique<NegativeExpression>(make_unique<NumberExpression>(3)),
        make_unique<NumberExpression>(4),
        '*'));

    std::cout << "All expressions:\n";
    vault.listAll();

    std::cout << "\nSolved:\n";
    vault.solveAll();

    std::cout << "\nMark trivial as used:\n";
    vault.markInvalid();

    std::cout << "\nNot used:\n";
    vault.listAllNotUsed();

    std::cout << "\nMake test (enter 2 indexes):\n";
    try
    {
        vault.makeTest(2, "test.txt");
    }
    catch (const runtime_error& e)
    {
        cout << e.what() << '\n';
    }
    catch (const out_of_range& e)
    {
        cout << e.what() << '\n';
    }
    catch (const logic_error& e)
    {
        cout << e.what() << '\n';
    }

    std::cout << "\nHistory:\n";
    vault.showHistory();

    std::cout << "\nUsed:\n";
    vault.listAllUsed();

    return 0;
}