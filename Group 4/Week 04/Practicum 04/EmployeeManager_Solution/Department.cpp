//
// Created by Boris Bozhilov on 3/17/2026.
//

#include "Department.h"

#include <cstring>
#include <iostream>

Department::Department() = default;

Department::Department(char name[127], unsigned int countOfEmployees,
    Employee employees[MAX_COUNT_OF_EMPLOYEES]){

    setName(name);
    setEmployees(countOfEmployees, employees);
}

Department::Department(char name[127]) {

    setName(name);
    countOfEmployees = 0;
}

Utils::ErrorCode Department::setName(const char name[127]) {

    if (name == nullptr) return Utils::ErrorCode::InvalidInput;
    if (name[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(name) >= 126) return Utils::ErrorCode::InvalidInput;

    strncpy(this -> name, name, 126);

    this -> name[126] = '\0';

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Department::setEmployees(const unsigned int countOfEmployees,
    const Employee employees[MAX_COUNT_OF_EMPLOYEES]) {

    if (countOfEmployees > MAX_COUNT_OF_EMPLOYEES) return Utils::ErrorCode::InvalidInput;

    this -> countOfEmployees = countOfEmployees;
    for (int i = 0; i < countOfEmployees; i++) {

        this -> employees[i] = employees[i];
    }
    return  Utils::ErrorCode::OK;
}


const char* Department::getName() const {
    return this -> name;
}

const Employee *Department::getEmployees() const {
    return this -> employees;
}


Utils::ErrorCode Department::addEmployee(const Employee &employee) {

    if (countOfEmployees >= Department::MAX_COUNT_OF_EMPLOYEES) return Utils::ErrorCode::ArrayIsFull;

    this -> employees[countOfEmployees++] = employee;

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Department::removeEmployee(unsigned int id) {

    int indexOfEmployee = -1;

    for (int i = 0; i < countOfEmployees; i++) {

        if (employees[i].getID() == id) {
            indexOfEmployee = i;
            break;
        }
    }

    if (indexOfEmployee == -1) return Utils::ErrorCode::NotFound;

    for (int i = indexOfEmployee + 1; i < countOfEmployees; i++) {

        employees[i - 1] = employees[i];
    }

    countOfEmployees--;

    return Utils::ErrorCode::OK;
}

unsigned int Department::getMaxEmployees() {
    return Department::MAX_COUNT_OF_EMPLOYEES;
}

void Department::printDepartmentInfo() const {

    std::cout << "Department: " << getName() << std::endl;

    for (int i = 0; i < countOfEmployees; i++) {

        employees[i].printEmployeeInfo();
    }

    std::cout << std::endl;
}




