#include <iostream>
#include "Company.h"
#include "Department.h"
#include "Employee.h"

int main() {
    Employee e1("ivan ivanov", "razrabotchik", 3000.0);
    Employee e2("maria petrova", "dizayner", 2500.0);
    Employee e3("petar georgiev", "menidzhur", 4000.0);

    std::cout << e1 << "\n";

    ++e1;   // заплатата нараства с 10%: 3000 → 3300
    std::cout << e1.getSalary() << "\n";   // 3300

    std::cout << (e1 > e2 ? "e1 e po-dobre platen" : "e2 e po-dobre platen") << "\n";

    Company& company = Company::getInstance();

    company.addDepartment("Engineering");
    company.addDepartment("Design");

    company.addEmployeeToDepartment("Engineering", e1);
    company.addEmployeeToDepartment("Engineering", e2);
    company.addEmployeeToDepartment("Design", e3);

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
        std::cout << "The company is active\n";

    Department* des = company["Design"];
    if (eng && des)
        std::cout << (*eng > *des ? "Engineering is bigger" : "Design is bigger") << "\n";
    company.removeEmployeeFromDepartment("Engineering", e2.getId());
    company.removeDepartment("Design");
}