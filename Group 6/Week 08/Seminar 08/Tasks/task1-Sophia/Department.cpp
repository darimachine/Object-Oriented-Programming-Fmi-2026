#include "Department.h"
#include <cstring>

void Department::free() {
    delete[] name;
    delete[] employees;
}

void Department::copyFrom(const Department& other) {
    if (other.name) {
        name = new char[std::strlen(other.name) + 1];
        std::strcpy(name, other.name);
    } 
    else name = nullptr;

    capacity = other.capacity;
    countOfEmployees = other.countOfEmployees;
    employees = new Employee[capacity];
    for (unsigned i = 0; i < countOfEmployees; ++i) {
        employees[i] = other.employees[i];
    }
}

void Department::resize() {
    capacity = (capacity == 0) ? 2 : capacity * 2;
    Employee* temp = new Employee[capacity];
    for (unsigned i = 0; i < countOfEmployees; ++i) {
        temp[i] = employees[i];
    }
        
    delete[] employees;
    employees = temp;
}

Department::Department() : name(nullptr), employees(nullptr), countOfEmployees(0), capacity(0) {}

Department::Department(const char* n, unsigned initCap) : countOfEmployees(0), capacity(initCap) {
    name = new char[std::strlen(n) + 1];
    std::strcpy(name, n);
    employees = new Employee[capacity];
}

Department::~Department() { 
    free(); 
}

Department::Department(const Department& other) { 
    copyFrom(other); 
}

Department& Department::operator=(const Department& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

const char* Department::getName() const { 
    return name; 
}

ErrorCode Department::addEmployee(const Employee& e) {
    if (countOfEmployees >= capacity) {
        resize();
    }
    employees[countOfEmployees++] = e;
    return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id) {
    for (unsigned i = 0; i < countOfEmployees; ++i) {
        if (employees[i].getId() == id) {
            employees[i] = employees[countOfEmployees - 1];
            countOfEmployees--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::NotFound;
}

double Department::getAverageSalary() const {
    if (countOfEmployees == 0) return 0.0;
    double sum = 0;
    for (unsigned i = 0; i < countOfEmployees; ++i) sum += employees[i].getSalary();
    return sum / countOfEmployees;
}

bool Department::operator>(const Department& other) const {
    if (countOfEmployees != other.countOfEmployees) 
        return countOfEmployees > other.countOfEmployees;
    return getAverageSalary() > other.getAverageSalary();
}

Employee& Department::operator[](unsigned idx) { 
    return employees[idx]; 
}
const Employee& Department::operator[](unsigned idx) const { 
    return employees[idx]; 
}

Department::operator bool() const { 
    return countOfEmployees > 0; 
}

Department& Department::operator()(double pct) {
    for (unsigned i = 0; i < countOfEmployees; ++i) {
        double current = employees[i].getSalary();
        employees[i].updateSalary(current * (1.0 + pct / 100.0));
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Department& d) {
    os << "Department: " << (d.name ? d.name : "N/A") << "\n";
    for (unsigned i = 0; i < d.countOfEmployees; ++i) os << "  " << d.employees[i] << "\n";
    return os;
}