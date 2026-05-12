#include <iostream>

#include "Employee.h"
#include "Department.h"
#include "Company.h"
#include "Utils.h"

int main() {

    Employee e1("Ivan Ivanon",   "Developer", 3000.0);
    Employee e2("Mria Petrova", "Designer",    2500.0);
    Employee e3("Petar Georgiev","Manager",    4000.0);

    std::cout << e1 << "\n";

    ++e1;   // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n";   // 3300

    std::cout << (e1 > e2 ? "e1 is paid better" : "e2 is paid better") << "\n";

    Company& company = Company::getInstance();

    company.addDepartment("Engineering", Utils::MAX_CAPACITY_OF_DEPARTMENTS);
    company.addDepartment("Design", Utils::MAX_CAPACITY_OF_DEPARTMENTS);

    company.addEmployeeToDepartment("Engineering", std::move(e1));
    company.addEmployeeToDepartment("Engineering", std::move(e2));
    company.addEmployeeToDepartment("Design",      std::move(e3));

    std::cout << company << "\n";

    // operator[] за достъп до отдел
    Department* eng = company["Engineering"];
    if (eng) {
        std::cout << (*eng)[0] << "\n";   // първият служител в Engineering
        (*eng)(15);                        // увеличава заплатите с 15%
        (*eng)(15)(10);                    // верижно — 15%, после още 10%
    }

    if (*eng)
        std::cout << "Engineering is active\n";

    if (company)
        std::cout << "Company is active\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering is larger" : "Design is larger") << "\n";

    company.removeEmployeeFromDepartment("Engineering", 2);
    company.removeDepartment("Design");

    return 0;
}
