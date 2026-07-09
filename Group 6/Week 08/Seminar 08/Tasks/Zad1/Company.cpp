#include "Company.h"

Company::Company()
{
    countOfDepartments = 0;
}

unsigned int Company::getDepartmentIdByName(const char* name)
{
    unsigned int id = invalidDepId;
    for (size_t i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(name, departments[i].getName()) == 0)
        {
            id = i;
        }
    }
    return id;
}


Company& Company::getInstance()
{
    static Company instance;
    return instance;

}

ErrorCode Company::addDepartment(const char* name)
{
    if (countOfDepartments>=9)
    {
        return ErrorCode::Full;
    }departments[countOfDepartments++] = Department(name);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    unsigned int id = getDepartmentIdByName(name);
    if (id== invalidDepId)
    {
        return ErrorCode::NotFound;
    }
    for (size_t i = id; i < countOfDepartments-1; i++)
    {
        departments[i] = departments[i + 1];
    }
    countOfDepartments--;

    return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    unsigned int id = getDepartmentIdByName(departmentName);
    if (id == invalidDepId)
    {
        return ErrorCode::NotFound;
    }
    Department& dep= departments[id];
    

    return dep.addEmployee(employee);
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    unsigned int id1 = getDepartmentIdByName(departmentName);
    if (id1 == invalidDepId)
    {
        return ErrorCode::NotFound;
    }
    Department& dep = departments[id1];


    return dep.removeEmployee(id);
}

Company::operator bool()
{
    if (countOfDepartments==0)
    {
        return false;
    }
    for (size_t i = 0; i < countOfDepartments; i++)
    {
        if (departments[i])
        {
            return true;
        }
    }
    return false;
}

Department* Company::operator[](const char* _depName)
{
    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(_depName, departments[i].getName())==0)
        {
            return &departments[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Company& c)
{
    os << "Number of departments: " << c.countOfDepartments<<";\n";
    for (size_t i = 0; i < c.countOfDepartments; i++)
    {
        os<< c.departments[i];
    }

    return os;
}
