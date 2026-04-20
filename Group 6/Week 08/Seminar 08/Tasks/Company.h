#pragma once
#include "Department.h"

constexpr unsigned MAX_DEPARTMENTS = 10;
constexpr unsigned INITIAL_DEPARTMENT_CAPACITY = 2;

class Company {
    Department departments[MAX_DEPARTMENTS];
    unsigned countOfDepartment_;
    Company();
    public:
    int findDepartment(const char* name)const;
    static Company &getInstance();

    Company(const Company& other)=delete ;
    Company& operator=(const Company& other)=delete;
    Company (Company&& other)= delete;
    Company& operator=(Company&& other)=delete;

    ErrorCode addDepartment(const char* name);
    ErrorCode removeDepartment(const char* name);
    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
    Department* operator[](const char* name);
    const Department* operator[](const char* name) const;
    explicit operator bool() const;
   friend std:: ostream& operator<<(std::ostream& os ,const Company& company);
};

std:: ostream& operator<<(std::ostream& os ,const Company& company);