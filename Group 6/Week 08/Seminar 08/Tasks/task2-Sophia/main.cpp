#include <iostream>
#include "Registration.h"
#include "Vehicle.h"
#include "VehicleList.h"

int main() {
    Registration r1("C1234AB");
    Registration r2("C5678XY");
    Registration r3("XY1111AB");

    std::cout << r1 << "\n";   // C1234AB

    Vehicle v1(r1, "Honda Civic",  2019, 150);
    Vehicle v2(r2, "Toyota Yaris", 2021, 120);
    Vehicle v3(r3, "BMW X5",       2019, 250);

    std::cout << v1 << "\n";
    // Сравнение по година: 2019 < 2021
    std::cout << (v1 < v2 ? "v1 e po stara" : "v2 e po stara") << "\n";  // v1
    // При равни години — по мощност: 150 < 250
    std::cout << (v1 < v3 ? "v1 e po slaba" : "v3 e po slaba") << "\n";  // v1

    VehicleList list(10);

    list += v1;   // слот 0
    list += v2;   // слот 1
    list += v3;   // слот 2
    list += v1;   // игнорира се — дублиран номер

    std::cout << list.size()     << "\n";   // 3
    std::cout << list.capacity() << "\n";   // 10
    std::cout << list.isEmpty()  << "\n";   // false
    std::cout << list.isFreeSlot(3) << "\n"; // true

    if (list)
        std::cout << "spisykyt e validen\n";

    std::cout << list << "\n";
    // [C1234AB] [C5678XY] [XY1111AB] [*] [*] ...

    std::cout << list("C")  << "\n";   // 2 — v1 и v2
    std::cout << list("XY") << "\n";   // 1 — v3

    list -= r2;   // премахва v2 → слот 1 става nullptr

    std::cout << list.size() << "\n";   // 2
    std::cout << list << "\n";
    // [C1234AB] [*] [XY1111AB] [*] ...

    list += v2;   // добавя на първия свободен слот → слот 1

    Vehicle* found = list.find(r1);
    if (found)
        std::cout << "namereno: " << *found << "\n";

    VehicleList list2(5);
    list2 += v1;
    list2 += v2;

    // Сравнение: list има 3 коли, list2 има 2 → list > list2
    std::cout << (list > list2 ? "list e po-golyam" : "list2 e po-golyam") << "\n";
}