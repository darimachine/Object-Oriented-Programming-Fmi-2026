#include <iostream>
#include "Employee.h"
#include "Department.h"
#include "Company.h"    

int main() {
    // Changed Bulgarian names and positions to English
    Employee e1("Ivan Ivanov", "Developer", 3000.0);
    Employee e2("Maria Petrova", "Designer", 2500.0);
    Employee e3("Peter Georgiev", "Manager", 4000.0);

    std::cout << e1 << "\n";

    ++e1;   // Salary increases by 10%: 3000 -> 3300
    std::cout << "New Salary: " << e1.getSalary() << "\n";

    std::cout << (e1 > e2 ? "e1 is paid better" : "e2 is paid better") << "\n";

    Company& company = Company::getInstance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design", e3);

    std::cout << company << "\n";

    // operator[] for accessing a department
    Department* eng = company["Engineering"];
    if (eng) {
        std::cout << "First employee in Engineering: " << (*eng)[0] << "\n";

        // Function call operator () for salary increase
        (*eng)(15);                       // Increases salaries by 15%
        (*eng)(15)(10);                   // Chain increase — 15%, then another 10%
    }

    // operator bool() check
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