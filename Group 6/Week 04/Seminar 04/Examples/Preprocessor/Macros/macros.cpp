#include <iostream>

#define PI 3.14159 // this tells the preprocessor to look for every occurence of PI
                    // and replace it with 3.14159

#define SUM(a, b) a + b // this tells the preprocessor to look for every call of SUM(a, b)
                        // and replace it with a + b directly

double getCircleArea(double radius) {
    return PI * radius * radius;
}

int main() {
    std::cout << getCircleArea(1) << '\n';
    std::cout << SUM(2, 3) << '\n'; // 5
}
