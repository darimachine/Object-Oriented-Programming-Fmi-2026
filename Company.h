#pragma once
#include "Department.h"
class Company
{
private:
    Department departments[10];
    unsigned countOfDepartments;

   

public:


    Company();
    Company(const Company&) = delete;
    Company& operator=(const Company&) = delete;
    Company(Company&&) = delete;
    Company& operator=(Company&&) = delete;

    static Company& getInstance();

    ErrorCode addDepartment(const char* name);
    ErrorCode removeDepartment(const char* name);

    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

    Department* operator[](const char* departmentName);
    const Department* operator[](const char* departmentName) const;

    explicit operator bool() const;

    friend std::ostream& operator<<(std::ostream& os, const Company& company);
};

