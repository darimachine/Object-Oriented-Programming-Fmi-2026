//
// Created by Vanina Laleva on 11.03.26.
//

#include "Department.h"

// #include <cstring>
#include<print>

Department::Department() = default;

Department::Department(const char *name, const Employee *employees, const unsigned int countOfEmployees) {
    strcpy(this->name, name);
    this->countOfEmployees = countOfEmployees;
    for (int i = 0; i < countOfEmployees; i++) {
        this->employees[i] = employees[i];
    }
}

ErrorCode Department::addEmployee(const Employee &employee) {
    if (countOfEmployees < MAX_EMPLOYEES) {
        if (!isInTheDepartment(employee)) {
            employees[countOfEmployees] = employee;
            countOfEmployees++;
            return (ErrorCode) ErrorCode::OK;
        } else {
            return (ErrorCode) ErrorCode::Duplicate;
        }
    }
    return (ErrorCode) ErrorCode::InvalidInput; // or NotFound
}

ErrorCode Department::removeEmployee(const unsigned int id) {
    if (id >= countOfEmployees) {
        return (ErrorCode) ErrorCode::InvalidInput;
    }
    for (int i = 0; i < countOfEmployees; i++) {
        if (employees[i].getId() == id) {
            for (int j = i; j < countOfEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            countOfEmployees--;
            return (ErrorCode) ErrorCode::OK;
        }
    }
    return (ErrorCode) ErrorCode::Error;
}

unsigned int Department::getMaxEmployees() {
    return MAX_EMPLOYEES;
}

void Department::setName(const char *Name) {
    strcpy(this->name, Name);
}

const char *Department::getName() const {
    return this->name;
}

unsigned int Department::getCountOfEmployees() const {
    return countOfEmployees;
}

bool Department::isInTheDepartment(const Employee &employee) const {
    for (int i = 0; i < countOfEmployees; i++) {
        if (strcmp(employees[i].getName(), employee.getName()) == 0 ||
            employees[i].getId() == employee.getId()) {
            return true;
        }
    }
    return false;
}

void Department::print() const {
    std::print("Department: {}\n", getName());
    // std::print("{}", getName());
    for (int i = 0; i < getCountOfEmployees(); i++) {
        std::print("{}. {} \n", employees[i].getId(), employees[i].getName());
    }
}
