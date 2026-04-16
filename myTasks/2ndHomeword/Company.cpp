#include  <print>
#include "Company.h"
#include  <iostream>
Company::Company() : countOfDepartments(0)
{}

Company& Company::getInstance()
{
    static Company instance;
    return instance;
}

ErrorCode Company::addDepartment(const char *DepName)
{
    if (!DepName)
        return ErrorCode::InvalidInput;

    if (countOfDepartments == MAX_DEPARTMENTS)
        return ErrorCode::FullDeparmentCont;

    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), DepName) == 0)
        {
            return ErrorCode::Duplicate;
        }
    }
    departments[countOfDepartments].setDepName(DepName);
    countOfDepartments++;
    //std::println("The department: {} is successfully added to the compaнъy", DepName);
    return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char *DepName)
{
    if (!DepName)
        return ErrorCode::InvalidInput;

    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), DepName) == 0)
        {
            departments[i] = departments[countOfDepartments - 1];
            countOfDepartments--;
           // std::println("This department is successfully removed");
            return ErrorCode::OK;
        }
    }

    std::println("This department is not in the company");
    return ErrorCode::NotFound;
}

ErrorCode Company::addEmployeeToDepartment(const char *departmentName, const Employee &employee)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), departmentName) == 0)
        {
            departments[i].addEmployee(employee);
           std::println("The employee is successfully added to: {} department", departments[i].getDepName());
            return ErrorCode::OK;
        }
    }
    std::println("The: {} department is not in the company", departmentName);
    return ErrorCode::NotFound;
}

ErrorCode Company::removeEmployeeFromDeaprtment(const char *departmentName, unsigned int id)
{
    if (!departmentName)
        return ErrorCode::InvalidInput;

    for (int i = 0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), departmentName) == 0)
        {
            departments[i].removeEmployee(id);
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

std::ostream& operator<<(std::ostream& os, const Company& currCompany)
{
    for (int i =0; i< currCompany.countOfDepartments; i++)
    {
        const Department&  currDepartmnet = currCompany.departments[i];
        std::println("The information for the {} department is: ", currDepartmnet.getDepName());
        std::cout<< currDepartmnet<<'\n';
    }

    return os;
}

Company::operator bool() const
{
    for (int i =0; i < countOfDepartments; i++)
    {
        const Department& currDep = departments[i];
        if (currDep)
        {
            return true;
        }
    }

    return false;
}

Department *Company::operator[](const char *DepName)
{
    if (!DepName)
    {
        return nullptr;
    }

    for (int i =0; i < countOfDepartments; i++)
    {
        if (strcmp(departments[i].getDepName(), DepName) == 0)
        {
            return  &departments[i];
        }
    }
    return  nullptr;
}


// int main()
// {
//     Employee e1("Иван Иванов",   "Разработчик", 3000.0);
//     Employee e2("Мария Петрова", "Дизайнер",    2500.0);
//     Employee e3("Петър Георгиев","Мениджър",    4000.0);
//
//     std::cout << e1 << "\n";
//
//     ++e1;
//     std::cout << e1.getSalary() << "\n";
//
//     std::cout << (e1 > e2 ? "e1 е по-добре платен" : "e2 е по-добре платен") << "\n";
//
//     Company& company = Company::getInstance();
//
//     company.addDepartment("Engineering");
//     company.addDepartment("Design");
//
//     company.addEmployeeToDepartment("Engineering", e1);
//     company.addEmployeeToDepartment("Engineering", e2);
//     company.addEmployeeToDepartment("Design",      e3);
//
//     std::cout << company << "\n";
//
//
//
//     return 0;
// }