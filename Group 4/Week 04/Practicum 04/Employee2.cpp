#include <iostream>
#include "Employee.h"

unsigned int Employee::idCounter_ = 0;

Employee::Employee() = default;

Employee::Employee(const char* name, const char* position, double salary): id_(++idCounter_), salary_(salary) {
    strcpy(name_, name);
    strcpy(position_, position);
}

const char * Employee::getName() const {return name_;}

unsigned Employee::getId() const {return id_;}

double Employee::getSalary() const {return salary_;}

ErrorCode Employee::updateSalary(double amount) {

    if (amount<=0) return ErrorCode::InvalidInput;
    salary_ += amount;
    return ErrorCode::OK;
}