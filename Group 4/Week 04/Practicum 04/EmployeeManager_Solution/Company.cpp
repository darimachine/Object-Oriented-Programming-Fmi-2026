//
// Created by Boris Bozhilov on 3/17/2026.
//

#include "Company.h"

#include <cstring>

Company &Company::getCompany() {

    static Company company;

    return company;
}

Company::Company() = default;


Utils::ErrorCode Company::searchDepartments(const char *departmentName, int &departmentIndex) const {

    if (departmentName == nullptr) return Utils::ErrorCode::InvalidInput;
    if (departmentName[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(departmentName) > 126) return Utils::ErrorCode::InvalidInput;

    departmentIndex = -1;

    for (int i = 0; i < countOfDepartments; i++) {

        if (strcmp(departments[i].getName(), departmentName) == 0) {
            departmentIndex = i;
            break;
        }
    }

    if (departmentIndex == -1) return Utils::ErrorCode::NotFound;

    return Utils::ErrorCode::OK;
}


Utils::ErrorCode Company::addDepartment(const char *name) {

    if (name == nullptr) return Utils::ErrorCode::InvalidInput;
    if (name[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(name) > 126) return Utils::ErrorCode::InvalidInput;

    char validName[127];
    strncpy(validName, name, 126);
    validName[126] = '\0';

    departments[countOfDepartments++].setName(validName);

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::removeDepartment(const char *name) {

    if (name == nullptr) return Utils::ErrorCode::InvalidInput;
    if (name[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(name) > 126) return Utils::ErrorCode::InvalidInput;

    int departmentIndex = -1;

    if (searchDepartments(name, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    for (int i = departmentIndex + 1; i < countOfDepartments; i++) {

        departments[i - 1] = departments[i];
    }

    countOfDepartments--;

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee) {

    if (departmentName == nullptr) return Utils::ErrorCode::InvalidInput;
    if (departmentName[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(departmentName) > 126) return Utils::ErrorCode::InvalidInput;

    int departmentIndex = -1;

    if (searchDepartments(departmentName, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    if (departments[departmentIndex].addEmployee(employee) == Utils::ErrorCode::ArrayIsFull)
        return Utils::ErrorCode::ArrayIsFull;

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, unsigned int employeeID) {

    if (departmentName == nullptr) return Utils::ErrorCode::InvalidInput;
    if (departmentName[0] == '\0') return Utils::ErrorCode::InvalidInput;
    if (strlen(departmentName) > 126) return Utils::ErrorCode::InvalidInput;

    int departmentIndex = -1;

    if (searchDepartments(departmentName, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    if (departments[departmentIndex].removeEmployee(employeeID) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    return Utils::ErrorCode::OK;
}

void Company::printCompanyInfo() const {

    for (int i = 0; i < countOfDepartments; i++) {

        departments[i].printDepartmentInfo();
    }
}
