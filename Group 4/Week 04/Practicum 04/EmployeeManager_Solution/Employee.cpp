//
// Created by Boris Bozhilov on 3/17/2026.
//

#include "Employee.h"

#include <cstring>
#include <iostream>
#include <print>

unsigned int Employee::countOfEmployees = 0;

Employee::Employee() = default;

Employee::Employee(char name[127], char position[127], double salary)
    : id(++countOfEmployees), salary(salary){

    this -> setName(name);
    this -> setPosition(position);
}


double Employee::getSalary() const {
    return this -> salary;
}

const char* Employee::getName() const {

    return this -> name;
}

const char* Employee::getPosition() const {

    return this -> position;
}

unsigned int Employee::getID() const {
    return this -> id;
}


Utils::ErrorCode Employee::setSalary(const double salary) {

    if (salary < 0) return Utils::ErrorCode::InvalidInput;

    this -> salary = salary;

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Employee::setPosition(const char position[127]) {

    if (position == nullptr) return Utils::ErrorCode::InvalidInput;
    if (position[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(position) > 126) return Utils::ErrorCode::InvalidInput;

    strncpy(this -> position, position, 126);

    this -> position[126] = '\0';

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Employee::setName(const char name[127]) {

    if (name == nullptr) return Utils::ErrorCode::InvalidInput;
    if (name[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(name) > 126) return Utils::ErrorCode::InvalidInput;

    strncpy(this -> name, name, 126);

    this -> name[126] = '\0';

    return Utils::ErrorCode::OK;
}


unsigned int Employee::getLastEmployeeID() {

    return countOfEmployees;
}

void Employee::printEmployeeInfo() const {

    std::cout << id << ", " << name << ", " << position << ", " << std::format("{:.2f}", salary) << std::endl;
}




