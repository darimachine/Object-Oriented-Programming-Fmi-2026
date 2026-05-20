//
// Created by Vanina Laleva on 11.03.26.
//

#include "Employee.h"
// #include "ErrorCode.h"

#include <cstring>

Employee::Employee() = default;

Employee::Employee(const unsigned int id, const char *name, const char *position, const double salary) {
    this->id = id;
    strcpy(this->name, name);
    strcpy(this->position, position);
    this->salary = salary;
}

double Employee::getSalary() const {
    return salary;
}

ErrorCode Employee::updateSalary(double amount) {
    this->salary += amount;
    return (ErrorCode) ErrorCode::OK;
}

unsigned int Employee::getId() const {
    return id;
}

const char *Employee::getName() const {
    return name;
}
