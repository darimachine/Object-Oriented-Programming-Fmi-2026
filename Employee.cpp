
#include "Employee.h"
#include <cstring>
#include <compare>
#include <iostream>

unsigned Employee::idCount = 0;

Employee::Employee() : Employee("Unknown", "Unknown", 0)
{
}

Employee::Employee(const char* name, const char* position, double salary)
    : salary(0)
{
    id = ++idCount;
    setName(name);
    setPosition(position);
    setSalary(salary);
}

void Employee::setName(const char* name)
{
    if (!name) return;
    if (strlen(name) >= MAX_SIZE) return;
    strcpy(this->name, name);
}

void Employee::setPosition(const char* position)
{
    if (!position) return;
    if (strlen(position) >= MAX_SIZE) return;
    strcpy(this->position, position);
}

void Employee::setSalary(double salary)
{
    if (salary < 0) {
        this->salary = 0;
        return;
    }
    this->salary = salary;
}

double Employee::getSalary() const
{
    return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
    salary += amount;
    return ErrorCode::OK;
}

unsigned Employee::getIndividualId() const
{
    return id;
}

unsigned Employee::getId() 
{
    return idCount;
}

Employee Employee::operator++(int)
{
    Employee temp(*this);
    ++(*this);
    return temp;
}

Employee& Employee::operator++()
{
    salary *= 1.1;
    return *this;
}

std::partial_ordering Employee::operator<=>(const Employee& other) const
{
    if (salary == other.salary)
        return id <=> other.id;

    return salary <=> other.salary;
}

std::ostream& operator<<(std::ostream& os, const Employee& v)
{
    os << v.name << " " << v.position << " " << v.salary;
    return os;
}
