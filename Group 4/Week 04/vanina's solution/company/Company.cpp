//
// Created by Vanina Laleva on 11.03.26.
//

#include<cstring>

#include "Company.h"

Company &Company::getInstance() {
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char *name) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            return (ErrorCode) ErrorCode::Duplicate;
        }
    }
    departments[countOfDepartments].setName(name);
    countOfDepartments++;
    return (ErrorCode) ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char *name) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            for (int j = i; j < countOfDepartments - 1; j++) {
                departments[j] = departments[j + 1];
            }
            countOfDepartments--;
            return (ErrorCode) ErrorCode::OK;
        }
    }
    return (ErrorCode) ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            if (departments[i].isInTheDepartment(employee)) {
                return (ErrorCode) ErrorCode::Duplicate;
            }
            departments[i].addEmployee(employee);
            return (ErrorCode) ErrorCode::OK;
        }
    }
    return (ErrorCode) ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, const Employee &employee) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            if (departments[i].isInTheDepartment(employee)) {
                departments[i].removeEmployee(employee.getId());
                return (ErrorCode) ErrorCode::OK;
            }
        }
    }

    return (ErrorCode) ErrorCode::NotFound;
}
