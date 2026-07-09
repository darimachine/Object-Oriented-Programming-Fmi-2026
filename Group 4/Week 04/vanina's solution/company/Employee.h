//
// Created by Vanina Laleva on 11.03.26.
//

#ifndef COMPANY_EMPLOYEE_H
#define COMPANY_EMPLOYEE_H

#include "ErrorCode.h"

constexpr int MAX_SIZE_STRING = 127;

class Employee {
private:
    unsigned int id = 0;
    char name[MAX_SIZE_STRING + 1] = "no name";
    char position[MAX_SIZE_STRING + 1] = "no position";
    double salary = 0.0;

public:
    Employee();

    Employee(unsigned int id, const char *name, const char *position, double salary);

    double getSalary() const;

    ErrorCode updateSalary(double amount);

    unsigned int getId() const;

    const char *getName() const;
};


#endif //COMPANY_EMPLOYEE_H
