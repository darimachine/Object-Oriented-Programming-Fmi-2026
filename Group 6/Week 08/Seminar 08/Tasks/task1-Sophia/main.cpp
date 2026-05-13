#include <iostream>
#include "Employee.h"
#include "Department.h"
#include "Company.h"

int main() {
    Employee e1("Ivan",   "razrabotchik", 3000.0);
    Employee e2("Maria", "dizainer",    2500.0);
    Employee e3("Peter","menidjur",    4000.0);

    std::cout << e1 << "\n";

    ++e1;   // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n";   // 3300

    std::cout << (e1 > e2 ? "e1 e po-dobre platen" : "e2 e po-dobre platen") << "\n";

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
        std::cout << "Engineering e aktiven\n";

    if (company)
        std::cout << "Firmata e aktivna\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering e po golqm" : "Design e po golqm") << "\n";

    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");
}