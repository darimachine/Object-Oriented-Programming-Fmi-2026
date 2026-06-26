#include "Company.h"
#include <cstring>
#include <iostream>

Company::Company() = default;

Company& Company::getInstance()
{
    static Company instance;
    return instance;
}

int Company::getIndexByName(const char* name) const
{
    if (!name) return -1;

    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (strcmp(departments[i].getName(), name) == 0)
            return (int)i;
    }

    return -1;
}

ErrorCode Company::addDepartment(const char* name)
{
    if (!name)
        return ErrorCode::InvalidInput;

    if (countOfDepartments >= 10)
        return ErrorCode::Full;

    if (getIndexByName(name) != -1)
        return ErrorCode::Duplicate;

    departments[countOfDepartments++] = Department(name, 1);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    if (!name)
        return ErrorCode::InvalidInput;

    int index = getIndexByName(name);
    if (index == -1)
        return ErrorCode::NotFound;

    for (unsigned i = index; i < countOfDepartments - 1; i++) {
        departments[i] = departments[i + 1];
    }

    --countOfDepartments;
    return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    int index = getIndexByName(departmentName);
    if (index == -1)
        return ErrorCode::NotFound;

    return departments[index].addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    int index = getIndexByName(departmentName);
    if (index == -1)
        return ErrorCode::NotFound;

    return departments[index].removeEmployee(id);
}

Department* Company::operator[](const char* name)
{
    int index = getIndexByName(name);
    if (index == -1)
        return nullptr;

    return &departments[index];
}

const Department* Company::operator[](const char* name) const
{
    int index = getIndexByName(name);
    if (index == -1)
        return nullptr;

    return &departments[index];
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
    for (unsigned i = 0; i < company.countOfDepartments; i++) {
        os << company.departments[i] << "\n";
    }
    return os;
}

Company::operator bool() const
{
    for (unsigned i = 0; i < countOfDepartments; i++) {
        if (departments[i])
            return true;
    }
    return false;
}