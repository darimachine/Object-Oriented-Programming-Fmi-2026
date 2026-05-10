#include "Employee.h"
#include "Developer.h"

Employee::Employee(const string& name, const string& email, double salary) :name(name),email(email),salary(salary)
{

}

const string& Employee::getName() const
{
    return name;
}

const string& Employee::getEmail() const
{
    return email;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::setSalary(double salary)
{
    if (salary < 0) {
        return;
    }
    this->salary = salary;
}

partial_ordering Employee::operator<=>(const Employee& other) const
{
    return salary <=> other.salary;
}

bool Employee::operator==(const Employee& other) const
{
    return email == other.email;
}


void Employee::print() const
{
    std::cout << "Име: " << name << "\n"
        << "Имейл: " << email << "\n"
        << "Заплата: " << salary << "\n";
}

ostream& operator<<(ostream& os, const Employee& e)
{
    os << "Heellllo\n";
    return os;
    // TODO: insert return statement here
}
