#include <iostream>
#include <print>
#include <cstring>

#include "Employee.h"

unsigned int Employee::Lastid = 0;

Employee::Employee()
{
    // std::cout<<"default constructor is called"<<'\n';
    name[0] = '\0';
    position[0] = '\0';
    salary = MIN_SALARY;
    ID = ++Lastid;
}

Employee::Employee(const char* inpName, const char* inpPosition, double inpSalary)
{
    setSalary(inpSalary);
    setName(inpName);
    setPosition(inpPosition);
    ID = ++Lastid;
}

void Employee::setSalary(double inpSalary)
{
    if (inpSalary < MIN_SALARY)
    {
        std::cout << "The inputed salary is invalid";
        salary = 0;
        return;
    }
    salary = inpSalary;
}

void Employee::setName(const char* inpName)
{
    if (!inpName)
    {
        return;
    }

    int inpNameLen = strlen(inpName);
    if (inpNameLen >= MAX_LEN_NAME)
    {
        std::cout << "The inputed name len is too long" << '\n';
        return;
    }

    strcpy(name, inpName);
}

void Employee::setPosition(const char *inpPosition)
{
    if (!inpPosition)
        return;

    int inpPositionLen = strlen(inpPosition);
    if (inpPositionLen >= MAX_LEN_NAME)
    {
        std::cout << "The inputed position len is too long" << '\n';
        return;
    }
    strcpy(position, inpPosition);
}

unsigned int Employee::getLastID()
{
    return Lastid;
}

double Employee::getSalary() const
{
    return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
    if (amount < MIN_SALARY)
    {
        return ErrorCode::InvalidInput;
    }
    salary = amount;
    return ErrorCode::OK;
}

// void Employee::printInfoEmployee() const
// {
//     std::cout << "ID: " << ID << " name: " << name << " position: " << position << "salary: " << salary << '\n';
// }
std::ostream& operator<<(std::ostream& os, const Employee& obj)
{
    os<<"Employee ID: "<<obj.ID<<" Name: "<<obj.name<<" position: "<<obj.position<<" salary: "<<obj.salary;
    return  os;
}


bool operator==(const Employee& lhs, const Employee& rhs)
{
    return lhs.salary == rhs.salary;
}

std::strong_ordering Employee::operator<=>(const Employee &other) const
{
    if (auto cmp = std::strong_order(salary, other.salary); cmp!= 0)
    {
        return cmp;
    }
    return  ID <=> other.ID;
}

Employee &Employee::operator++()
{
    salary += salary *0.1;
    return* this;
}

Employee Employee::operator++(int dummy)
{
    Employee temp =*this;
    ++(*this);
    return  temp;
}

// const char * Employee::printExitCode(ErrorCode currErrorCode) const
// {
//     switch (currErrorCode)
//     {
//         case ErrorCode::OK:
//             return "OK";
//         case ErrorCode::InvalidInput:
//             return "Invalid input";
//         case ErrorCode::Duplicate:
//             return "Duplicate";
//         case ErrorCode::NotFound:
//             return "Not found";
//     }
// }
//
const char *Employee::getEmployeeName() const
{
    return name ? name : "";
}

const char *Employee::getPosition() const
{
    return  position;
}

unsigned int Employee::getId() const
{
    return  ID;
}

// int main()
// {
//     Employee first("Ivan Ivanov", "Senior Software Engineer", 5000);
//     Employee second("Mariya Petrova", "Junior Developer", 3200);
//     Employee third("Georgi Dimitrov", "QA Automation", 4800);
//
//     std::cout<<first++<<'\n';
//     std::cout<<first<<'\n';
//


//     //
//     return 0;
// }