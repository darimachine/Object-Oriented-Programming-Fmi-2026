#include <iostream>

#include "Accumulator.h"
#include "Engine.h"
#include "Tire.h"

int main() {
    Tire t("BMW", "black and white", 159, 32, 20);
    std::cout << t << std::endl;

    Engine engine("Toyota", "blue and black", 350);
    std::cout << engine << std::endl;

    Accumulator acc(245, 1465, "Nissan", "very powerful");
    std::cout << acc << std::endl;
}