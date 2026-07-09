//
// Created by Boris Bozhilov on 3/17/2026.
//

#ifndef EMPLOYEEMANAGER_COMPANY_H
#define EMPLOYEEMANAGER_COMPANY_H
#include "Department.h"


class Company {

private:

    static constexpr unsigned int MAX_COUNT_OF_DEPARTMENTS = 10;

    unsigned int countOfDepartments = 0;
    Department departments[MAX_COUNT_OF_DEPARTMENTS];

    Company();

    Utils::ErrorCode searchDepartments(const char* departmentName, int &departmentIndex) const;

public:

    Company(const Company& other) = delete;
    Company& operator= (const Company&) = delete;

    Company(Company&&) = delete;
    Company& operator=(Company&&) = delete;

    static Company& getCompany();

    Utils::ErrorCode addDepartment(const char* name);
    Utils::ErrorCode removeDepartment(const char* name);
    Utils::ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    Utils::ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned int employeeID);

    void printCompanyInfo() const;
};


#endif //EMPLOYEEMANAGER_COMPANY_H