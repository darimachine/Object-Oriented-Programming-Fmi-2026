//
// Created by Vanina Laleva on 11.03.26.
//

#include "Employee.h"
// #include "ErrorCode.h"

#include <cstring>

unsigned int Employee::nextId = 0;

Employee::Employee() = default;

Employee::Employee(const char *name, const char *position, const double salary) {
    id = nextId++;
    strcpy(this->name, name);
    strcpy(this->position, position);
    this->salary = salary;
}

double Employee::getSalary() const {
    return salary;
}

ErrorCode Employee::updateSalary(double amount) {
    this->salary += amount;
    return (ErrorCode) ErrorCode::OK;
}

unsigned int Employee::getLastId() {
    return nextId;
}

unsigned int Employee::getId() const {
    return id;
}

const char *Employee::getName() const {
    return name;
}

const char *Employee::getPosition() const {
    return position;
}

Employee &Employee::operator++() {
    salary *= 1.1;
    return *this;
}

Employee Employee::operator++(int) {
    Employee old(*this);
    ++salary;
    return old;
}

//
std::ostream &operator<<(std::ostream &os, const Employee &employee) {
    os << employee.getName() << " is a " << employee.getPosition() << "\n";
    os << employee.getSalary();
    return os;
}

bool operator==(const Employee &lhs, const Employee &rhs) {
    if (lhs.getSalary() == rhs.getSalary()) {
        return lhs.getId() == rhs.getId();
    }
    return false;
}

std::strong_ordering operator<=>(const Employee &lhs, const Employee &rhs) {
    if (lhs.getSalary() < rhs.getSalary()) {
        return std::strong_ordering::less;
    }
    if (lhs.getSalary() > rhs.getSalary()) {
        return std::strong_ordering::greater;
    }
    return lhs.getId() <=> rhs.getId();
}
