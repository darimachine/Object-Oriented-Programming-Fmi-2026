//
// Created by Vanina Laleva on 11.03.26.
//

#ifndef COMPANY_EMPLOYEE_H
#define COMPANY_EMPLOYEE_H

#include "ErrorCode.h"
#include<iostream>

constexpr int MAX_SIZE_STRING = 127;

class Employee {
private:
    unsigned int id = 0;
    static unsigned int nextId;
    char name[MAX_SIZE_STRING + 1] = "no name";
    char position[MAX_SIZE_STRING + 1] = "no position";
    double salary = 0.0;

public:
    Employee();

    Employee(const char *name, const char *position, double salary);

    double getSalary() const;

    ErrorCode updateSalary(double amount);

    //
    static unsigned int getLastId();

    //
    unsigned int getId() const;

    const char *getName() const;

    const char *getPosition() const;

    //
    Employee &operator++();

    Employee operator++(int);
};

std::ostream &operator<<(std::ostream &os, const Employee &employee);

bool operator==(const Employee &lhs, const Employee &rhs);

std::strong_ordering operator<=>(const Employee &lhs, const Employee &rhs);

#endif //COMPANY_EMPLOYEE_H
