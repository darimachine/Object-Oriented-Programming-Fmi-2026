#pragma once
#include <iostream>
#include "Functions.h"

class Employee {
    static unsigned int id;
    unsigned int thisId;
    char name[127];
    char possition[127];
    double salary = 0;
public:
    Employee() = default;
    Employee(char* name, char* possition, double salary) {
        if (strlen(name) > 127 || strlen(possition) > 127 || salary < 0) {
            std::cout << ((int)ErrorCode::InvalidInput);
        }
        else
        {
            strcpy(this->name, name);
            strcpy(this->possition, possition);
            this->salary = salary;
            thisId = id++;
        }
    }
    double getSalary() const {
        return salary;
    }
    ErrorCode updateSalary(double amount) {
        if (amount > 0) {
            salary = amount;
            return ErrorCode::OK;
        }
        else
        {
            return ErrorCode::InvalidInput;
        }
    }
    static unsigned int getLastId() {
        return id-1;
    }
    const char* getName() const {
        return name;
    }
    static void lowerTheCount() {
        id--;
    }
};
