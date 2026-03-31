//
// Created by Vanina Laleva on 11.03.26.
//

#ifndef COMPANY_DEPARTMENT_H
#define COMPANY_DEPARTMENT_H

#include "Employee.h"

constexpr int MAX_EMPLOYEES = 15;

class Department {
private:
    char name[MAX_SIZE_STRING + 1] = "no name";
    Employee employees[MAX_EMPLOYEES];
    unsigned int countOfEmployees = 0;

public:
    Department();

    // Department(const char *name);
    Department(const char *name, const Employee *employees, unsigned int countOfEmployees);

    ErrorCode addEmployee(const Employee &employee);

    ErrorCode removeEmployee(unsigned int id);

    static unsigned int getMaxEmployees();

    void setName(const char *Name);

    const char *getName() const;

    unsigned int getCountOfEmployees() const;

    bool isInTheDepartment(const Employee &employee) const;

    void print() const;
};


#endif //COMPANY_DEPARTMENT_H
