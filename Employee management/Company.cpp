#include "Company.h"
using std::cout;
using std::string;
using std::cin;
using std::endl;
bool equal(const char* str1, const char* str2)
{
    bool check = true;
    int size = 0;
    while (str1!='\0')
    {
        if (str1[size] != str2[size])
        {
            check = false;
            break;
        }
        size++;
    }
    return check;
}
Company::Company()
{
    countOfDepartments = 0;
}
Company& Company::getInstance()
{ 
    if (instance == nullptr) 
    {
        instance = new Company();
    }
}
ErrorCode Company::addDepartment(const char* n)
{
    ErrorCode e = ErrorCode::OK;
    
    if (countOfDepartments + 1 <= DSIZE)
    {
        Department d(n, 0);
        departments[countOfDepartments] = d;
        countOfDepartments++;
    }
    else
    {
        e = ErrorCode::Full;
    }
    return e;
}
ErrorCode Company::removeDepartment(const char* n)
{
    bool check = false;
    int index = 0;
    ErrorCode e = ErrorCode::OK;
    Department d[DSIZE];
    for (int i = 0; i < countOfDepartments; i++)
    {
        if (equal(departments[i].getName(), n))
        {
           
            check = true;

        }
        else
        {
            d[index] = departments[i];
            index++;
        }
    }
    if (check)
    {
        countOfDepartments--;
        for (int i = 0; i < countOfDepartments; i++)
        {
            departments[i] = d[i];
        }
    }
    else
    {
        e = ErrorCode::NotFound;
    }
    return e;
}
ErrorCode Company::addEmployeeToDepartment(const char* d, const Employee& e)
{
    bool check = false;
    int index = 0;
    ErrorCode error = ErrorCode::OK;
    for (int i = 0; i < countOfDepartments; i++)
    {
        if (equal(departments[i].getName(), d))
        {
            check = true;
            index = i;
            break;
        }
    }
    if (check)
    {
        error =departments[index].addEmployee(e);
    }
    else
    {
        error = ErrorCode::NotFound;
    }
    return error;
}
ErrorCode Company::removeEmployeeFromDepartment(const char* d, unsigned i)
{
    bool check = false;
    int index = 0;
    ErrorCode error = ErrorCode::OK;
    for (int j = 0; j < countOfDepartments; j++)
    {
        if (equal(departments[j].getName(), d))
        {
            check = true;
            index = j;
            break;
        }
    }
    if (check)
    {
        error = departments[index].removeEmployee(i);
    }
    else
    {
        error = ErrorCode::NotFound;
    }
    return error;
}
std::ostream& operator<<(std::ostream& out, Company& C)
{
    out << "Departments:" << endl;
    for (int i = 0; i < C.countOfDepartments; i++)
    {
        out << C.departments[i];
    }
}
Company::operator bool() const
{
    bool check = true;
    if (countOfDepartments == 0)
    {
        check = false;
    }
    else
    {
        for (int i = 0; i < countOfDepartments; i++)
        {
            if (departments[i])
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
    }
    return check;
}
Department* Company::operator[](const char* d)
{
    
    for (int i = 0; i < countOfDepartments; i++)
    {
        if (equal(departments[i].getName(), d))
        {
            return &departments[i];
        }
    }
    return nullptr;
}