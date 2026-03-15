#pragma once
#include <iostream>
#include "Functions.h"

class Department {
    char name[127];
    Employee employees[15];
    unsigned countOfEmployees = 0;
public:
    Department() = default;
    Department(char* name) {
        if (strlen(name) > 127) std::cout << "Wrong input";
        else strcpy(this->name, name);
    }
    ErrorCode addEmployee(const Employee& employee) {
        if (countOfEmployees >= 15)
            return ErrorCode::InvalidInput;

        employees[countOfEmployees++] = employee;       
        return ErrorCode::OK;
    }
    ErrorCode removeEmployee(unsigned id) {
        if (id >= countOfEmployees)
            return ErrorCode::NotFound;

        swapEmployees(employees, countOfEmployees, id);
        countOfEmployees--;
        Employee::lowerTheCount();
        return ErrorCode::OK;
    }
    static unsigned getMaxEmployees() {
        return 15;
    }
    const char* getName() const {
        return name;
    }
};