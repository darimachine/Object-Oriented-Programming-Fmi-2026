#include "Company.h"

int main()
{
    Company& c = Company::getInstance();

    c.addDepartment("Maths");
    c.addDepartment("Finance");
    c.addDepartment("Economy");
    c.addDepartment("IT");

    Employee e1("Ivan", "politic", 1500);
    Employee e2("Katerina", "financier", 1300);
    Employee e3("Mihail", "manager", 1200);
    Employee e4("Ivana", "engineer", 1400);

    e2.updateSalary(1500.25);

    c.addEmployeeToDepartment("Maths", e1);
    c.addEmployeeToDepartment("Finance", e2);
    c.addEmployeeToDepartment("Economy", e3);
    c.addEmployeeToDepartment("IT", e4);

    c.printCompany();

    c.removeDepartment("Maths");
    c.removeEmployeeFromDepartment("Economy", e3.getId());

    std::println("After change:");
    c.printCompany();
    
    return 0;
}
