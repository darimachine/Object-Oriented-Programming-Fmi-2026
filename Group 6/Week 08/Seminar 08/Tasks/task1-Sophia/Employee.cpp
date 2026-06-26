#include "Employee.h"
#include <cstring>

unsigned Employee::nextId = 1;

Employee::Employee() : id(0), salary(0.0) {
    name[0] = '\0';
    position[0] = '\0';
}

Employee::Employee(const char* n, const char* p, double s) : id(nextId++), salary(s) {
    std::strncpy(name, n, 127); 
    name[127] = '\0';
    std::strncpy(position, p, 127); 
    position[127] = '\0';
}

unsigned Employee::getId() const { 
    return id; 
}
double Employee::getSalary() const { 
    return salary; 
}
unsigned Employee::getLastId() { 
    return nextId - 1; 
}

ErrorCode Employee::updateSalary(double amount) {
    if (amount < 0) return ErrorCode::InvalidInput;
    salary = amount;
    return ErrorCode::OK;
}

bool Employee::operator>(const Employee& other) const {
    if (salary != other.salary) return salary > other.salary;
    return id > other.id;
}

Employee& Employee::operator++() {
    salary *= 1.10;
    return *this;
}

Employee Employee::operator++(int) {
    Employee temp = *this;
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    os << "{" << e.id << "} " << e.name << " (" << e.position << ") - " << e.salary << " lv.";
    return os;
}