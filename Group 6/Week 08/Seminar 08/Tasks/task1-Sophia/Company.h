#pragma once
#include "Department.h"

class Company {
private:
    Department departments[10];
    unsigned countOfDepartments;

    Company();
    Company(const Company&) = delete;
    Company& operator=(const Company&) = delete;
    Company(Company&&) = delete;
    Company& operator=(Company&&) = delete;

public:
    static Company& getInstance();

    ErrorCode addDepartment(const char* name);
    ErrorCode removeDepartment(const char* name);
    ErrorCode addEmployeeToDepartment(const char* deptName, const Employee& e);
    ErrorCode removeEmployeeFromDepartment(const char* deptName, unsigned id);

    friend std::ostream& operator<<(std::ostream& os, const Company& c);
    operator bool() const;
    Department* operator[](const char* deptName);
};