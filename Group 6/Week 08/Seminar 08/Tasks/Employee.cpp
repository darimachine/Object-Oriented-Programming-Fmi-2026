#include "Employee.h"
#include <cstring>

static constexpr double MAX_DIFF = 0.0000001;

static bool isSalaryEqual(const double x, const double y) {
        return std::abs(x - y) < MAX_DIFF;
}

unsigned Employee::lastID = 0;

unsigned Employee::nextID() {
    return ++lastID;
}

unsigned Employee::getLastID() {
    return lastID;
}

std::strong_ordering Employee::operator<=>(const Employee& other) const {
    if (isSalaryEqual(salary, other.salary)) {
        return id <=> other.id;
    }
    return salary < other.salary ? std::strong_ordering::less : std::strong_ordering::greater;
}

Employee & Employee::operator++() {
    salary *= 1.10;
    return *this;
}

Employee Employee::operator++(int dummy) {
    Employee temp = *this;
    salary *= 10;
    return temp;
}

Employee::Employee() : id(nextID()), salary(0) {
    name[0] = '\0';
    position[0] = '\0';
}

Employee::Employee(const char *name, const char *position, double salary) : id(nextID()), salary(salary) {
    if (!name || !position) {
        this->name[0] = '\0';
        this->position[0] = '\0';
        return;
    }
    strncpy(this->name, name, MAX_SIZE);
    this->name[MAX_SIZE] = '\0';
    strncpy(this->position, position, MAX_SIZE);
    this->position[MAX_SIZE] = '\0';
}

double Employee::getSalary() const {
    return salary;
}

unsigned Employee::getId() const {
    return id;
}

ErrorCode Employee::updateSalary(double amount) {
    if (amount < 0) {
        return ErrorCode::InvalidInput;
    }
    salary = amount;
    return ErrorCode::OK;
}

std::ostream & operator<<(std::ostream &os, const Employee &emp) {
    os << "Employee ID: " << emp.id << '\n'
       << "Employee Name: " << emp.name << '\n'
       << "Employee Position: " << emp.position << '\n'
       << "Employee Salary: " << emp.salary << "€\n";
    return os;
}
