#include<iostream>

#include "Company.h"

int main()
{
    Employee e1("Ivan Ivanov", "Developer", 3000.0);
    Employee e2("Maria Petrova", "Designer", 2500.0);
    Employee e3("Petar Georgiev", "Manager", 4000.0);

    std::cout << e1 << "\n";

    ++e1;   // salary increases by 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n";   // 3300

    std::cout << (e1 > e2 ? "e1 is better paid" : "e2 is better paid") << "\n";

    Company& company = Company::instance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design", e3);

    std::cout << company << "\n";

    // operator[] for accessing a department
    Department* eng = company["Engineering"];
    if (eng) {
        std::cout << (*eng)[0] << "\n";   // first employee in Engineering
        (*eng)(15);                        // increases salaries by 15%
        (*eng)(15)(10);                    // chained — 15%, then another 10%
    }

    if (*eng)
        std::cout << "Engineering is active\n";

    if (company)
        std::cout << "The company is active\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering is larger" : "Design is larger") << "\n";

    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");

    return 0;
}