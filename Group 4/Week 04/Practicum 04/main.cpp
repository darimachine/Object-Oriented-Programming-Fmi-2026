#include <iostream>
#include "Employee.h"
#include "Department.h"
#include "Company.h"
using std::cin;
using std::cout;

int main() {
    Company& company = Company::getInstance();

    company.addDepartment("IT");

    Employee e1("Ivan", "Manager", 2000);
    company.addEmployeeToDepartment("IT", e1);
    company.removeEmployeeFromDepartment("IT",0);

    return 0;
}