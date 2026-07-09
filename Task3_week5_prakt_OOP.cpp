#include <iostream>
#include"MultiSet.h"

int main()
{
    MultiSet a(5);
    MultiSet b(5);

    a.addNum(1);
    a.addNum(1);
    a.addNum(2);
    a.addNum(4);
    a.addNum(4);
    a.addNum(4);

    b.addNum(1);
    b.addNum(2);
    b.addNum(2);
    b.addNum(4);

    std::print("A:");
    a.printAll();

    std::print("\nB:");
    b.printAll();

    MultiSet intersection = MultiSet::getIntersection(a, b);
    std::print("\nIntersection:");
    intersection.printAll();

    MultiSet Union = MultiSet::getUnion(a, b);
    std::print("\nUnion:");
    Union.printAll();

    a.removeNum(4);
    std::println("\nAfter change:");
    a.printAll();

    std::println("\nCount of 1 in A: {}", a.countNum(1));
    std::println("Count of 4 in A: {}", a.countNum(4));

    return 0;
}
