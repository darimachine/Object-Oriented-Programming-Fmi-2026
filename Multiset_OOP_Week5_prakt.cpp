#include <iostream>
#include"Multiset.h"

int main()
{
    MultiSet A(10);
    MultiSet B(10);

    A.add(3);
    A.add(3);
    A.add(5);
    A.add(6);

    B.add(3);
    B.add(5);
    B.add(5);

    std::println("A: ");
    A.printAll();

    std::println("B: ");
    B.printAll();

    MultiSet I = MultiSet::getIntersection(A, B);
    MultiSet U = MultiSet::getUnion(A, B);

    std::println("Intersection: ");
    I.printAll();

    std::println("Union: ");
    U.printAll();
}
