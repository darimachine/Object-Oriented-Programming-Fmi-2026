#include "Company.h"

Company& Company::getInstance()
{
    static Company companyInstance{};
    return companyInstance;
}

ErrorCode Company::addDepartment(const char* name)
{
    if (!name) return ErrorCode::InvalidInput;
    if (this->countOfDepartments == MAX_DEPARTMENTS) return ErrorCode::Full;
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), name) == 0)
        {
            return ErrorCode::Duplicate;
        }
    }
    Department department(name, 8);
    this->departments[this->countOfDepartments++] = department;
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char* name)
{
    if (!name) return ErrorCode::InvalidInput;
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), name) == 0)
        {
            std::swap(this->departments[i], this->departments[countOfDepartments - 1]);
            countOfDepartments--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char* departmentName, const Employee& employee)
{
    if (!departmentName) return ErrorCode::InvalidInput;
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), departmentName) == 0)
        {
            this->departments[i].addEmployee(employee);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDepartment(const char* departmentName, unsigned id)
{
    if (!departmentName) return ErrorCode::InvalidInput;
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), departmentName) == 0)
        {
            this->departments[i].removeEmployee(id);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

Company::operator bool() const
{
    if (this->countOfDepartments == 0) return false;
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (this->departments)
        {
            return true;
        }
    }
    return false;
}

Department* Company::operator[](const char* name)
{
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), name) == 0)
        {
            return &this->departments[i];
        }
    }
    return nullptr; 
}

const Department* Company::operator[](const char* name) const
{
    for (unsigned i = 0; i < this->countOfDepartments; i++)
    {
        if (strcmp(this->departments[i].getName(), name) == 0)
        {
            return &this->departments[i];
        }
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const Company& company)
{
    for (unsigned i = 0; i < company.countOfDepartments; i++)
    {
        os << company.departments[i] << '\n';
    }
    return os;
}
