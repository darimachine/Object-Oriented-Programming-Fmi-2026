//
// Created by Boris Bozhilov on 4/13/2026.
//

#include "Company.h"

#include <ostream>
#include <utility>
#include <cstring>

// utility functions
Utils::ErrorCode Company::findDepartmentIndex(const char *departmentName, unsigned int &departmentIndex) const {

    for (unsigned int i = 0; i < countOfDepartments; i++) {

        if (strcmp(departments[i].getName(), departmentName) == 0) {
            departmentIndex = i;
            return Utils::ErrorCode::OK;
        }
    }

    return Utils::ErrorCode::NotFound;
}

// rule fo 5
Company::Company() : departments(new Department[MAX_COUNT_OF_DEPARTMENTS]){}

Company::~Company() {

    delete[] departments;
    departments = nullptr;

    countOfDepartments = 0;
}

Company &Company::getInstance() {

    static Company company = Company();

    return company;
}


// methods
Utils::ErrorCode Company::addDepartment(const char *departmentName, const unsigned int departmentCapacity) {

    if (countOfDepartments >= MAX_COUNT_OF_DEPARTMENTS) return Utils::ErrorCode::Full;

    departments[countOfDepartments++] = Department(departmentName, departmentCapacity);

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::removeDepartment(const char *departmentName) {

    unsigned int departmentIndex = 0;

    if (findDepartmentIndex(departmentName, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    for (unsigned int i = departmentIndex + 1; i < countOfDepartments; i++) {

        departments[i - 1] = departments[i];
    }

    countOfDepartments--;

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::addEmployeeToDepartment(const char *departmentName, Employee&& employee) const {

    unsigned int departmentIndex = 0;

    if (findDepartmentIndex(departmentName, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    if (departments[departmentIndex].hasNoMoreCapacity()) return Utils::ErrorCode::Full;

    departments[departmentIndex].addEmployee(std::move(employee));

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, const unsigned int employeeID) const {

    unsigned int departmentIndex = 0;

    if (findDepartmentIndex(departmentName, departmentIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    return departments[departmentIndex].removeEmployee(employeeID);
}

// operators
std::ostream& operator<<(std::ostream &output, const Company &company) {

    output << "This company has " << company.countOfDepartments << " departments:" << std::endl;

    for (unsigned int i = 0; i < company.countOfDepartments; i++) {

        output << company.departments[i] << std::endl;
    }

    return output;
}

Company::operator bool() const {

    if (countOfDepartments == 0) return false;

    for (unsigned int i = 0; i < countOfDepartments; i++) {

        if (departments[i]) return true;
    }

    return false;
}

Department *Company::operator[](const char *departmentName) const {

    unsigned int departmentIndex = 0;

    if (findDepartmentIndex(departmentName, departmentIndex) == Utils::ErrorCode::NotFound) return nullptr;

    return &departments[departmentIndex];
}




