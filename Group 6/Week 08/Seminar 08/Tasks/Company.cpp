#include "Company.h"
#include <algorithm>
#include <cstring>

Company::Company() : countOfDepartments(0) {
}

int Company::findDeparment(const char *name) const {
    if (!name) {
        return -1;
    }
    for (int i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0) {
            return i;
        }
    }
    return -1;
}

Company& Company::getInstance() {
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char *name) {
    if (!name || name[0] == '\0') {
        return ErrorCode::InvalidInput;
    }
    if (countOfDepartments >= MAX) {
        return ErrorCode::Full;
    }
    if (findDeparment(name) != -1) {
        return ErrorCode::Duplicate;
    }

    departments[countOfDepartments++] = Department(name, 10);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char *name) {
    int index = findDeparment(name);
    if (index == -1) {
        return ErrorCode::InvalidInput;
    }

    for (int i = index + 1; i < countOfDepartments; i++) {
        departments[i - 1] = departments[i];
    }

    departments[--countOfDepartments] = Department();
    return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee) {
    int index = findDeparment(departmentName);
    if (index == -1) {
        return ErrorCode::InvalidInput;
    }
    return departments[index].addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, unsigned id) {
    int index = findDeparment(departmentName);
    if (index == -1) {
        return ErrorCode::InvalidInput;
    }
    return departments[index].removeEmployee(id);
}

/*bool Company::isFirmActive() const {
    return countOfDepartments == 0;
}*/

Company::operator bool() const {
    for (int i = 0; i < countOfDepartments; i++) {
        if (departments[i]) {
            return true;
        }
    }
    return false;
}

Department * Company::operator[](const char *name) {
    int index = findDeparment(name);
    return (index == -1) ? nullptr : &departments[index];
}

std::ostream & operator<<(std::ostream &os, const Company &comp) {
    os << "All company deparments\n";
    for (int i = 0; i < comp.countOfDepartments; i++) {
        os << comp.departments[i];
    }
    return os;
}
