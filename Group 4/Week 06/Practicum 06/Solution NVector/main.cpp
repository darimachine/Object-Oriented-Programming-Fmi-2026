#include <iostream>

#include "NVector.h"

int main() {

    int v1Data[] = {1, 2, 3, 1, 2, 3};
    int v2Data[] = {1, 2, 3};
    int v3Data[] = {10, 20, 30};
    int v4Data[] = {-2, 1, 10};

    NVector v1 = NVector(v1Data, std::size(v1Data));
    NVector v2 = NVector(v2Data, std::size(v2Data));
    NVector v3 = NVector(v3Data, std::size(v3Data));
    NVector v4 = NVector(v4Data, std::size(v4Data));

    std::cout << (v1 > v2) << std::endl;
    std::cout << (v1 < v3) << std::endl;
    std::cout << (v2 <= v3) << std::endl;
    std::cout << (v2 >= v4) << std::endl;
    std::cout << (v4 != v3) << std::endl;

    std::cout << (v3 % v4);

    return 0;
}
