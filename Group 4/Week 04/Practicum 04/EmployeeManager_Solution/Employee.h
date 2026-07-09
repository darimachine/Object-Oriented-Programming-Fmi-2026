//
// Created by Boris Bozhilov on 3/17/2026.
//

#ifndef EMPLOYEEMANAGER_EMPLOYEE_H
#define EMPLOYEEMANAGER_EMPLOYEE_H

#include "Utils.h"

class Employee {
private:
    unsigned int id = 0;
    char name[127] = "";
    char position[127] = "";
    double salary = -1;

    static unsigned int countOfEmployees;

public:
    Employee();
    Employee(char name[127], char position[127], double salary);
    static unsigned int getLastEmployeeID();

    double getSalary() const;
    const char* getName() const;
    const char* getPosition() const;
    unsigned int getID() const;

    Utils::ErrorCode setSalary(double salary);
    Utils::ErrorCode setName(const char name[127]);
    Utils::ErrorCode setPosition(const char position[127]);

    void printEmployeeInfo() const;
};

#endif //EMPLOYEEMANAGER_EMPLOYEE_H