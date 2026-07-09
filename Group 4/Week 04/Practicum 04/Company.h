#pragma once
#include "Department.h"

constexpr unsigned MAX_DEPARTMENTS = 10;

class Company {
    Department departments[MAX_DEPARTMENTS];
    unsigned countOfDepartment_;
    Company();
    public:
    int findDepartment(const char* name)const;
    static Company &getInstance();
    ErrorCode addDepartment(const char* name);
    ErrorCode removeDepartment(const char* name);
    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

};