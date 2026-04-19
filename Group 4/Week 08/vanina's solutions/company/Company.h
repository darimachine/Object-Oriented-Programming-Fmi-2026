//
// Created by Vanina Laleva on 11.03.26.
//

#ifndef COMPANY_COMPANY_H
#define COMPANY_COMPANY_H

#include "Department.h"

constexpr int MAX_DEPARTMENTS = 10;

class Company {
private:
    Department departments[MAX_DEPARTMENTS];
    unsigned int countOfDepartments = 0;

    Company() = default;

public:
    Company(const Company &other) = delete;

    Company &operator=(const Company &other) = delete;

    static Company &getInstance();

    unsigned int getCountOfDepartments() const;

    ErrorCode addDepartment(const char *name);

    ErrorCode removeDepartment(const char *name);

    ErrorCode addEmployeeToDepartment(const char *departmentName, const Employee &employee);

    ErrorCode removeEmployeeFromDepartment(const char *departmentName, const Employee &employee);

    ErrorCode removeEmployeeFromDepartment(const char *departmentName, unsigned int newId);

    //
    void printDepartments() const;

    Department *operator[](const char *departmentName);

    operator bool() const;
};

std::ostream &operator<<(std::ostream &os, const Company &company);

#endif //COMPANY_COMPANY_H
