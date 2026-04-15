#pragma once
#include "Department.h"

static constexpr int MAX = 10;

class Company {
private:
    Department departments[MAX];
    unsigned countOfDepartments{};

    Company();
    int findDeparment(const char* name) const;

public:
    static Company& getInstance();

    Company(const Company& other) = delete;
    Company& operator=(const Company& other) = delete;
    Company(Company&& other) = delete;
    Company& operator=(Company&& other) = delete;

    ErrorCode addDepartment(const char* name);
    ErrorCode removeDepartment(const char* name);
    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);

    friend std::ostream& operator<<(std::ostream& os, const Company& comp);

    //bool isFirmActive() const;
    explicit operator bool() const;

    Department* operator[](const char* name);

};