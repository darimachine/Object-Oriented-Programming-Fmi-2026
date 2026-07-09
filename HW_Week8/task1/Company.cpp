#include "Company.h"

Company::Company() : countOfDepartments(0) 
{

}

Company& Company::getInstance()
{
	static Company instance;
	return instance;
}

ErrorCode Company::addDepartment(const char* name)
{
    if (!name)
    {
        return ErrorCode::InvalidInput;
    }
    if (countOfDepartments >= 10)
    {
        return ErrorCode::Full;
    }
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(), name) == 0)
        {
            return ErrorCode::Duplicate;
        }
    }
    departments[countOfDepartments++] = Department(name);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    if (!name)
    {
        return ErrorCode::InvalidInput;
    }
    for (unsigned i = 0; i < countOfDepartments; i++) 
    {
        if (strcmp(departments[i].getName(), name) == 0) 
        {
            for (unsigned j = i; j < countOfDepartments - 1; j++)
            {
                departments[j] = departments[j + 1];
            }
            departments[countOfDepartments - 1] = Department();
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
            return departments[i].addEmployee(employee);
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
            return departments[i].removeEmployee(id);
        }
    }
    return ErrorCode::NotFound;
}

Department* Company::operator[](const char* departmentName) 
{
    if (!departmentName)
    {
        return nullptr;
    }
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
            return &departments[i];
        }
    }
    return nullptr;
}

const Department* Company::operator[](const char* departmentName) const 
{
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getName(), departmentName) == 0)
        {
            return &departments[i];
        }
    }
    return nullptr;
}

Company::operator bool() const 
{
    for (unsigned i = 0; i < countOfDepartments; i++)
    {
        if (departments[i].getCount() > 0)
        {
            return true;
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
    os << "Company" << std::endl;
    for (unsigned i = 0; i < company.countOfDepartments; i++)
    {
        os << company.departments[i] << std::endl;
    }
    return os;
}