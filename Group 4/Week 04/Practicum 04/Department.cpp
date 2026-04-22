#include "Department.h"
#include <iostream>

Department::Department()= default;
Department::Department(const char* name): countOfEmployees_(0) {
    strcpy(name_, name);
}
ErrorCode Department:: addEmployee(const Employee &employee){
    if (countOfEmployees_>= MAX_EMPLOYEES) {return ErrorCode::InvalidInput;}

    for (int i = 0; i < countOfEmployees_; i++) {
        if (employees_[i].getId() == employee.getId()) {
            return ErrorCode::Duplicate;
        }
    }

employees_[countOfEmployees_] = employee;
    countOfEmployees_++;
    return ErrorCode::OK;
}
ErrorCode Department::removeEmployee(unsigned id) {
int personNum=-1;
    if (id<=0) {
        return ErrorCode::InvalidInput;
    }

    for (int i=0; i<countOfEmployees_; i++) {
        if (employees_[i].getId() == id) {
            personNum = i;
        }
    }

    if (personNum == -1) {
        return ErrorCode::NotFound;
    }

    for (int i=personNum; i<MAX_EMPLOYEES-1; i++) {
        employees_[i] = employees_[i+1];
    }

countOfEmployees_--;
    return ErrorCode::OK;
}
unsigned Department::getMaxEmployees() {
    return MAX_EMPLOYEES;
}

const char * Department::getName() const {
    return name_;
}
