//
// Created by Boris Bozhilov on 4/13/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPANY_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPANY_H
#include "Department.h"


class Company {

private:

    static constexpr unsigned int MAX_COUNT_OF_DEPARTMENTS = 10;

    Department* departments = nullptr;
    unsigned int countOfDepartments = 0;

    // rule of 5
    Company();
    ~Company();

    // utility functions
    Utils::ErrorCode findDepartmentIndex(const char* departmentName, unsigned int& departmentIndex) const;

public:

    // rule of 5 - deleted
    Company(const Company& other) = delete;
    Company& operator=(const Company& other) = delete;
    Company(Company&& other) = delete;
    Company& operator=(Company&& other) = delete;

    // function that returns the only instance of Company
    static Company& getInstance();

    // methods
    Utils::ErrorCode addDepartment(const char* departmentName, const unsigned int departmentCapacity);
    Utils::ErrorCode removeDepartment(const char* departmentName);
    Utils::ErrorCode addEmployeeToDepartment(const char* departmentName, Employee&& employee) const;
    Utils::ErrorCode removeEmployeeFromDepartment(const char* departmentName, const unsigned int employeeID) const;

    // operators
    friend std::ostream& operator<<(std::ostream& output, const Company& company);
    explicit operator bool() const;
    Department* operator[](const char* departmentName) const;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPANY_H
