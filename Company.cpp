#define _CRT_SECURE_NO_WARNINGS
#include "Company.h"

Company::Company() : countOfDepartments(0) 
{
}

Company& Company::getInstance() {
    static Company instance;

    return instance;
}

ErrorCode Company::addDepartment(const char* name) {
    if (!name || name[0] == '\0') {
        return ErrorCode::InvalidInput;
    }

    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (std::strcmp(departments[i].getName(), name) == 0) {
            return ErrorCode::Duplicate;

        }
    }
    if (countOfDepartments >= 10) {
        return ErrorCode::Full;
    }
    departments[countOfDepartments++] = Department(name, 4);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name) {
    if (!name || name[0] == '\0') {
        return ErrorCode::InvalidInput;
    }

    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (std::strcmp(departments[i].getName(), name) == 0) {
            for (unsigned j = i; j + 1 < countOfDepartments; j++) {
                departments[j] = departments[j + 1];
            }
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee) {
    Department* dep = (*this)[departmentName];
    if (!dep) {
        return ErrorCode::NotFound;
    }

    return dep->addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id) {
    Department* dep = (*this)[departmentName];
    if (!dep) {
        return ErrorCode::NotFound;
    }

    return dep->removeEmployee(id);
}

Department* Company::operator[](const char* departmentName) {
    if (!departmentName) {
        return nullptr;
    }

    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (std::strcmp(departments[i].getName(), departmentName) == 0) {
            return &departments[i];
        }
    }

    return nullptr;
}

const Department* Company::operator[](const char* departmentName) const {
    if (!departmentName) {
        return nullptr;
    }

    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (std::strcmp(departments[i].getName(), departmentName) == 0) {
            return &departments[i];
        }
    }

    return nullptr;
}

Company::operator bool() const {
    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (departments[i]) {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Company& company) {
    os << "Company structure:\n";
    for (unsigned i = 0; i < company.countOfDepartments; i++) {
        os << company.departments[i];
    }
    return os;
}
