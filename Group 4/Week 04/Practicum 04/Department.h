#pragma once
#include "Employee.h"
constexpr unsigned int MAX_EMPLOYEES = 15;

class Department {
    char name_[127];
    Employee employees_[MAX_EMPLOYEES];
    unsigned countOfEmployees_;
public:
    Department();
    Department(const char* name);
    ErrorCode addEmployee(const Employee &employee);
    ErrorCode removeEmployee(unsigned id);
    static unsigned getMaxEmployees();
    const char* getName()const;
};