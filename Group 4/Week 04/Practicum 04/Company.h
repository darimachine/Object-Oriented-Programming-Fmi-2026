#pragma once
#include <iostream>
#include "Functions.h"

class Company {

    Department departments[10];
    unsigned countOfDepartments = 0;
private:
    Company() = default;

public:
    static Company& getInstance() {
        static Company c;
        return c;
    }
    ErrorCode addDepartment(char* name) {
        if (countOfDepartments >= 10)
            return ErrorCode::InvalidInput;
        if (find(departments, name, countOfDepartments) != -1)
            return ErrorCode::Duplicate;
        Department d(name);
        departments[countOfDepartments++] = d;

        return ErrorCode::OK;
    }
    ErrorCode removeDepartment(const char* name) {
        int index = find(departments, name,countOfDepartments);
        if (index == -1) return ErrorCode::NotFound;
        else
        {
            swapDepartments(departments, countOfDepartments, index);
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee) {
        int index = find(departments, departmentName,countOfDepartments);
        if (index == -1)return ErrorCode::NotFound;
        departments[index].addEmployee(employee);
        return ErrorCode::OK;
    }
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id) {
        int index = find(departments, departmentName,countOfDepartments);
        if (index == -1)return ErrorCode::NotFound;
        departments[index].removeEmployee(id);
        return ErrorCode::OK;
    }
};