//
// Created by Boris Bozhilov on 3/17/2026.
//

#ifndef EMPLOYEEMANAGER_DEPARTMENT_H
#define EMPLOYEEMANAGER_DEPARTMENT_H
#include "Employee.h"


class Department {

private:
    static constexpr unsigned int MAX_COUNT_OF_EMPLOYEES = 15;

    char name[127];
    unsigned int countOfEmployees = 0;
    Employee employees[MAX_COUNT_OF_EMPLOYEES];

public:

    Department();
    Department(char name[127]);
    Department(char name[127], unsigned int countOfEmployees, Employee employees[MAX_COUNT_OF_EMPLOYEES]);

    Utils::ErrorCode addEmployee(const Employee& employee);
    Utils::ErrorCode removeEmployee(unsigned int id);

    Utils::ErrorCode setName(const char name[127]);
    const char* getName() const;

    Utils::ErrorCode setEmployees(unsigned int countOfEmployees,
        const Employee employees[MAX_COUNT_OF_EMPLOYEES]);
    const Employee* getEmployees() const;

    static unsigned int getMaxEmployees();

    void printDepartmentInfo() const;
};


#endif //EMPLOYEEMANAGER_DEPARTMENT_H