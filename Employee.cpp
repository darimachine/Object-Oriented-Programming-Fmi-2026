#include <iostream>
#include "Employee.h"

unsigned Employee::countEmployee = 0;

Employee::Employee() : id(0), salary(0)
{
    name[0] = '\0';
    position[0] = '\0';
}


Employee::Employee(const char* name, const char* position, double salary) :salary(salary), id(++countEmployee) {
    strcpy_s(this->name, MAX_LEN+1, name);
    strcpy_s(this->position, MAX_LEN + 1, position);
}



double Employee::getSalary() const {
    return salary;
};

ErrorCode Employee::updateSalary(double amount) {
    if (amount < 0) {
        return ErrorCode::InvalidInput;
    }

    if (amount == getSalary()) {
        return ErrorCode::Duplicate;
    }

    salary = amount;
    return ErrorCode::OK;
};

unsigned int Employee::getId() const {
    return id;
}

unsigned Employee::getLastEmployeeId() {
    return countEmployee;
}