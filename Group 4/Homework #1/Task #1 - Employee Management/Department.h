//
// Created by Boris Bozhilov on 4/13/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DEPARTMENT_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DEPARTMENT_H
#include <compare>

#include "Employee.h"


class Department {

private:

    char* name = nullptr;
    Employee* employees = nullptr;
    unsigned int countOfEmployees = 0;
    unsigned int capacity = 0;

    // utility functions
    Utils::ErrorCode findEmployeeInArray(const unsigned int employeeID, unsigned int& employeeIndex) const;
    double getAverageSalaryOfDepartment() const;
    void copyDepartmentDataFromOther(const Department& other);
    void moveDepartmentDataFromOther(Department&& other);

public:

    // utility functions
    bool isValid() const;
    const char* getName() const;
    bool hasNoMoreCapacity() const;

    // rule of 5
    Department();
    Department(const char* name, const unsigned int capacity);

    Department(const Department& other);
    Department& operator=(const Department& other);

    Department(Department&& other) noexcept;
    Department& operator=(Department&& other) noexcept;

    ~Department();

    // methods
    Utils::ErrorCode addEmployee(Employee&& employee);
    Utils::ErrorCode removeEmployee(unsigned int employeeID);

    // operators
    friend std::ostream& operator<<(std::ostream& output, const Department& department);
    bool operator==(const Department& other) const;
    std::strong_ordering operator<=>(const Department& other) const;
    Employee operator[](const unsigned int employeeIndex) const;
    Employee& operator[](const unsigned int employeeIndex);
    explicit operator bool() const;
    Department& operator()(const unsigned int rate);
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_DEPARTMENT_H
