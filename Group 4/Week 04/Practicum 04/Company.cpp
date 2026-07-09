#include "Company.h"
#include<string>

Company::Company():countOfDepartment_(0) {}

int Company::findDepartment(const char *name)const {
    int indexOfDepartment=-1;
    if (name[0] == '\0') {
        return -2;
    }

    for (int i=0; i<countOfDepartment_; i++) {
        if (strcmp(departments[i].getName(),name) ==0) {
            indexOfDepartment=i;
        }
    }
    return indexOfDepartment;
}

Company & Company::getInstance() {
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char *name) {
    if (countOfDepartment_ >= MAX_DEPARTMENTS) {
        return ErrorCode::InvalidInput;
    }
    departments[countOfDepartment_]= Department(name);
    countOfDepartment_++;
    return ErrorCode::OK;
}


ErrorCode Company::removeDepartment(const char *name) {
    int indexOfDepartment=findDepartment(name);
    if (indexOfDepartment==-2) {
        return ErrorCode::InvalidInput;
    }

    if (indexOfDepartment == -1) {
        return ErrorCode::NotFound;
    }

    for (int i=indexOfDepartment; i<MAX_DEPARTMENTS-1; i++) {
        departments[i] = departments[i+1];
    }

    countOfDepartment_--;
    return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee) {
    int indexOfDepartment=findDepartment(departmentName);
    if (indexOfDepartment == -2) {
        return ErrorCode::InvalidInput;
    }

    if (indexOfDepartment == -1) {
        return ErrorCode::NotFound;
    }

    departments[indexOfDepartment].addEmployee(employee);
    return ErrorCode::OK;
}

ErrorCode Company::removeEmployeeFromDepartment(const char *departmentName, unsigned id) {
    int indexOfDepartment=findDepartment(departmentName);
    if (indexOfDepartment == -2) {
        return ErrorCode::InvalidInput;
    }

    if (indexOfDepartment == -1) {
        return ErrorCode::NotFound;
    }

    departments[indexOfDepartment].removeEmployee(id);
    return ErrorCode::OK;
}
