#include "Employee.h"
#include <iostream>
#include "Company.h"

int main()
{
    Employee e1("Ivan Ivanov", "Developer", 3000.0);
    Employee e2("Maria Petrova", "Designer", 2500.0);
    Employee e3("Petar Georgiev", "Manager", 4000.0);

    std::cout << e1 << std::endl;

    ++e1;   // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << std::endl;   // 3300

    std::cout << (e1 > e2 ? "e1 is better paid" : "e2 is better paid") << std::endl;;

    Company& company = Company::getInstance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design", e3);

    std::cout << company;

    // operator[] за достъп до отдел
    Department* eng = company["Engineering"];
    if (eng) {
        std::cout << (*eng)[0] << "\n";   // първият служител в Engineering
        (*eng)(15);                        // увеличава заплатите с 15%
        (*eng)(15)(10);                    // верижно — 15%, после още 10%
    }

    if (*eng)
    {
        std::cout << "Engineering is active\n";
    }

    if (company)
        std::cout << "The firm is active\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering is bigger" : "Design is bigger") << "\n";

    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");
}