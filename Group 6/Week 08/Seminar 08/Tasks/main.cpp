/*
#include "ErrorCode.h"
#include "Employee.h"
#include "Department.h"
#include "Company.h"


int main() {
    Employee e1("Иван Иванов",   "Разработчик", 3000.0);
    Employee e2("Мария Петрова", "Дизайнер",    2500.0);
    Employee e3("Петър Георгиев","Мениджър",    4000.0);

    std::cout << e1 << "\n";

    ++e1;   // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n";   // 3300

    std::cout << (e1 > e2 ? "e1 е по-добре платен" : "e2 е по-добре платен") << "\n";

    Company& company = Company::getInstance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design",      e3);

    std::cout << company << "\n";

    // operator[] за достъп до отдел
    Department* eng = company["Engineering"];
    if (eng) {
        std::cout << (*eng)[0] << "\n";   // първият служител в Engineering
        (*eng)(15);                        // увеличава заплатите с 15%
        (*eng)(15)(10);                    // верижно — 15%, после още 10%
    }

    if (*eng)
        std::cout << "Engineering е активен\n";

    if (company)
        std::cout << "Фирмата е активна\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering е по-голям" : "Design е по-голям") << "\n";

    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");
}
*/

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
    std::cout << (v1 < v2 ? "v1 е по-стара" : "v2 е по-стара") << "\n";  // v1
    // При равни години — по мощност: 150 < 250
    std::cout << (v1 < v3 ? "v1 е по-слаба" : "v3 е по-слаба") << "\n";  // v1

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
        std::cout << "Списъкът е валиден\n";

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
        std::cout << "Намерено: " << *found << "\n";

    VehicleList list2(5);
    list2 += v1;
    list2 += v2;

    // Сравнение: list има 3 коли, list2 има 2 → list > list2
    std::cout << (list > list2 ? "list е по-голям" : "list2 е по-голям") << "\n";
}
