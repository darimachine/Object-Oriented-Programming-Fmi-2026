//
// Created by Vanina Laleva on 11.03.26.
//

#ifndef COMPANY_DEPARTMENT_H
#define COMPANY_DEPARTMENT_H

#include "Employee.h"

constexpr int MAX_EMPLOYEES = 15;

class Department {
private:
    char name[MAX_SIZE_STRING + 1] = "no name";
    Employee *employees{nullptr};
    unsigned int countOfEmployees = 0;
    unsigned int capacity = MAX_EMPLOYEES;

    //
    void copyFrom(const Department &other);

    void free();

    void moveFrom(Department &&other);

    void resize(unsigned int newCapacity);

public:
    Department();

    Department(const char *name, const Employee *employees, unsigned int countOfEmployees);

    ErrorCode addEmployee(const Employee &employee);

    ErrorCode removeEmployee(unsigned int id);

    static unsigned int getMaxEmployees();

    void setName(const char *Name);

    const char *getName() const;

    unsigned int getCountOfEmployees() const;

    double getAverageSalary() const;

    //
    bool isInTheDepartment(const Employee &employee) const;

    bool isInTheDepartment(unsigned int searchId) const;

    void printEmployees() const;

    // void print() const;

    //
    const Employee &operator[](int index) const;

    Employee &operator[](int index);

    operator bool() const;

    //
    Department &operator()(int percent);
};

//
std::ostream &operator<<(std::ostream &os, const Department &department);

std::strong_ordering operator<=>(const Department &lhs, const Department &rhs);


#endif //COMPANY_DEPARTMENT_H
