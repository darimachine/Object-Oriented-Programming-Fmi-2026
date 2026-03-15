#include <iostream>
#include "Company.h"
#include "Employee.h"

void printResult(ErrorCode code)
{
    switch (code)
    {
    case ErrorCode::OK:
        std::cout << "OK\n";
        break;
    case ErrorCode::Duplicate:
        std::cout << "Duplicate\n";
        break;
    case ErrorCode::NotFound:
        std::cout << "NotFound\n";
        break;
    case ErrorCode::InvalidInput:
        std::cout << "InvalidInput\n";
        break;
    }
}

int main()
{
    Company& company = Company::getInstance();

    std::cout << "---- ADD DEPARTMENTS ----\n";

    printResult(company.addDepartment("IT"));
    printResult(company.addDepartment("HR"));
    printResult(company.addDepartment("Finance"));

    std::cout << "Trying duplicate department:\n";
    printResult(company.addDepartment("IT"));

    std::cout << "\n---- CREATE EMPLOYEES ----\n";

    Employee e1("Ivan Petrov", "Programmer", 3000);
    Employee e2("Maria Ivanova", "Manager", 4500);
    Employee e3("Georgi Georgiev", "Accountant", 3500);

    std::cout << "IDs: "
        << e1.getId() << " "
        << e2.getId() << " "
        << e3.getId() << "\n";

    std::cout << "\n---- ADD EMPLOYEES ----\n";

    printResult(company.addEmployeeToDepartment("IT", e1));
    printResult(company.addEmployeeToDepartment("HR", e2));
    printResult(company.addEmployeeToDepartment("Finance", e3));

    std::cout << "Trying to add employee to non-existing department:\n";
    printResult(company.addEmployeeToDepartment("Marketing", e1));

    std::cout << "\n---- UPDATE SALARY ----\n";

    printResult(e1.updateSalary(3200));
    std::cout << "New salary: " << e1.getSalary() << "\n";

    std::cout << "Trying duplicate salary:\n";
    printResult(e1.updateSalary(3200));

    std::cout << "\n---- REMOVE EMPLOYEE ----\n";

    printResult(company.removeEmployeeFromDepartment("IT", e1.getId()));

    std::cout << "Removing non-existing employee:\n";
    printResult(company.removeEmployeeFromDepartment("IT", 999));

    std::cout << "\n---- REMOVE DEPARTMENT ----\n";

    printResult(company.removeDepartment("HR"));

    std::cout << "Removing non-existing department:\n";
    printResult(company.removeDepartment("HR"));

    std::cout << "\n---- TEST FINISHED ----\n";

    return 0;

}
