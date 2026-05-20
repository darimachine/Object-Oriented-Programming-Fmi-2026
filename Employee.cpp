#include "Employee.h"
#include <cstring>

unsigned Employee::countEmployee = 0;

Employee::Employee() : id(0), salary(0.0)
{
    name[0] = '\0';
    position[0] = '\0';
}


Employee::Employee(const char* name, const char* position, double salary) :salary(salary), id(++countEmployee) {
    
    if (name) {
        strcpy_s(this->name, MAX_LEN + 1, name);
    }
        
    else {
        this->name[0] = '\0';
    }
        
    if (position) {
        strcpy_s(this->position, MAX_LEN + 1, position);
    }
        
    else {
        this->position[0] = '\0';
    }
        
}

double Employee::getSalary() const {
    return salary;
};

ErrorCode Employee::updateSalary(double amount) {
    if (amount < 0) {
        return ErrorCode::InvalidInput;
    }

    if (amount == getSalary()) {
        return ErrorCode::InvalidInput;
    }

    salary = amount;
    return ErrorCode::OK;
};

unsigned int Employee::getId() const {
    return id;
}

unsigned Employee::getLastEmployeeId() {
    return countEmployee;
}

Employee& Employee::operator++()
{
    salary = salary * 1.1;
    return *this;
}

Employee Employee::operator++(int dummy)
{
    Employee result(*this);
    salary = salary * 1.1;
    return result;
}

std::ostream& operator<<(std::ostream& os, const Employee& empl)
{
    os << empl.name << " " << empl.position << " " << empl.id << " " << empl.salary;
    return os;
}


bool operator==(const Employee& lhs, const Employee& rhs)
{
    return salaryEqual(lhs.getSalary(), rhs.getSalary()) && lhs.getId() == rhs.getId();
}

std::strong_ordering operator<=>(const Employee& lhs, const Employee& rhs)
{
    double lSalary = lhs.getSalary();
    double rSalary = rhs.getSalary();

    if (!salaryEqual(lSalary, rSalary))
    {
        if (lSalary < rSalary) {
            return std::strong_ordering::less;
        } 
        if (lSalary > rSalary) {
             return std::strong_ordering::greater;
        }
    }

    return lhs.getId() <=> rhs.getId();
}
