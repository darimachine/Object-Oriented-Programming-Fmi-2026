#include "Company.h"
#include <cstring>

Company::Company() : countOfDepartments(0) {}

Company& Company::getInstance() {
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char* name) {
    if (countOfDepartments >= 10) return ErrorCode::Full;
    departments[countOfDepartments++] = Department(name, 2);
    return ErrorCode::OK;
}

Department* Company::operator[](const char* deptName) {
    for (unsigned i = 0; i < countOfDepartments; ++i) {
        if (std::strcmp(departments[i].getName(), deptName) == 0) 
            return &departments[i];
    }
    return nullptr;
}

ErrorCode Company::addEmployeeToDepartment(const char* deptName, const Employee& e) {
    Department* d = (*this)[deptName];
    if (!d) return ErrorCode::NotFound;
    return d->addEmployee(e);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* deptName, unsigned id) {
    Department* d = (*this)[deptName];
    if (!d) return ErrorCode::NotFound;
    return d->removeEmployee(id);
}

ErrorCode Company::removeDepartment(const char* name) {
    for (unsigned i = 0; i < countOfDepartments; ++i) {
        if (std::strcmp(departments[i].getName(), name) == 0) {
            departments[i] = departments[countOfDepartments - 1];
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

Company::operator bool() const {
    for (unsigned i = 0; i < countOfDepartments; ++i) 
        if (departments[i]) return true;
    return false;
}

std::ostream& operator<<(std::ostream& os, const Company& c) {
    os << "company structure: \n";
    for (unsigned i = 0; i < c.countOfDepartments; ++i) os << c.departments[i];
    return os;
}