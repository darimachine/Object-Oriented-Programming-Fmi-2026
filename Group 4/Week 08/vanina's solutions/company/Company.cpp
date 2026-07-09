//
// Created by Vanina Laleva on 11.03.26.
//

#include<cstring>

#include "Company.h"

Company &Company::getInstance() {
    static Company instance;
    return instance;
}

unsigned int Company::getCountOfDepartments() const {
    return countOfDepartments;
}

ErrorCode Company::addDepartment(const char *name) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            return ErrorCode::Duplicate;
        }
    }
    departments[countOfDepartments].setName(name);
    countOfDepartments++;
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char *name) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            for (int j = i; j < countOfDepartments - 1; j++) {
                departments[j] = departments[j + 1];
            }
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            // if (departments[i].isInTheDepartment(employee)) {
            //     return ErrorCode::Duplicate;
            // }
            return departments[i].addEmployee(employee);
            // return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, const Employee &employee) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            if (departments[i].isInTheDepartment(employee)) {
                departments[i].removeEmployee(employee.getId());
                return ErrorCode::OK;
            }
        }
    }

    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, unsigned int searchId) {
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            if (departments[i].isInTheDepartment(searchId)) {
                departments[i].removeEmployee(searchId);
                return ErrorCode::OK;
            }
        }
    }
    return ErrorCode::NotFound;
}

void Company::printDepartments() const {
    for (int i = 0; i < countOfDepartments; i++) {
        std::cout << departments[i].getName() << " with employees: \n";
        departments[i].printEmployees();
    }
}

Department *Company::operator[](const char *departmentName) {
    for (int i = 0; i < getCountOfDepartments(); i++) {
        if (strcmp(departments[i].getName(), departmentName) == 0) {
            return &departments[i];
        }
    }
    return nullptr;
}

Company::operator bool() const {
    for (int i = 0; i < countOfDepartments; i++) {
        if (departments[i]) {
            return true;
        }
    }
    return false;
}

//
std::ostream &operator<<(std::ostream &os, const Company &company) {
    os << "Departments: \n";
    company.printDepartments();
    return os;
}
