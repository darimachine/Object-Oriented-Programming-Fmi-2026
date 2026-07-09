#include <iostream>
#include "NVector.h"

int main() {
    NVector v(4);
    std::cin >> v;          

    NVector v2(4);
    std::cin >> v2;         

    NVector result = v + v2;
    std::cout << result << "\n";                  

    result *= 2;
    std::cout << "Scaled: " << result << "\n";    

    if (v | v2)
        std::cout << "Orthogonal\n";

    if (v || v2)
        std::cout << "Parallel\n";

    NVector zero(3);
    if (!zero) std::cout << "Zero vector\n";
    if (v)     std::cout << "v is non-zero\n";

    
    NVector squares = v([](int x) { return x * x; });
    std::cout << "Squares: " << squares << "\n";

    
    std::cout << "Size: " << ~v << "\n";

    int arr1[3] = { 1,2,3 };
    int arr2[3] = { 1,2,4 };
    int arr3[3] = { 1,2,3 };
    NVector va(arr1, 3);
    NVector vb(arr2, 3);
    NVector vc(arr3, 3);

    std::cout << (va == vc ? "equal" : "non-equal") << "\n";  
    std::cout << (va < vb ? "va < vb" : "va >= vb") << "\n";  
    std::cout << (vb > va ? "vb > va" : "vb <= va") << "\n";  

    
    auto cmp = va <=> vb;
    if (cmp < 0)       std::cout << "va is smaller\n";
    else if (cmp == 0) std::cout << "equal\n";
    else               std::cout << "va is bigger\n";
}
