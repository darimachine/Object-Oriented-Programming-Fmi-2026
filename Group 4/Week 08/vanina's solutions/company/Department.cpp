//
// Created by Vanina Laleva on 11.03.26.
//

#include "Department.h"

// #include <algorithm>
#include<print>

void Department::copyFrom(const Department &other) {
    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;
    strcpy(name, other.name);

    for (unsigned int i = 0; i < other.countOfEmployees; i++) {
        employees[i] = other.employees[i];
    }
}

void Department::free() {
    delete[] employees;
}

void Department::moveFrom(Department &&other) {
    strcpy(name, other.name);
    employees = other.employees;
    capacity = other.capacity;
    countOfEmployees = other.countOfEmployees;

    strcpy(other.name, "");
    other.employees = nullptr;
    other.capacity = MAX_EMPLOYEES;
    other.countOfEmployees = 0;
}

void Department::resize(unsigned int newCapacity) {
    Employee *newData = new Employee[newCapacity];
    for (unsigned int i = 0; i < countOfEmployees; i++) {
        newData[i] = employees[i];
    }

    delete[] employees;
    employees = newData;
    capacity = newCapacity;
}

Department::Department() = default;

Department::Department(const char *name, const Employee *employees, const unsigned int countOfEmployees) {
    strcpy(this->name, name);
    this->countOfEmployees = countOfEmployees;
    this->employees = new Employee[countOfEmployees];
    for (int i = 0; i < countOfEmployees; i++) {
        this->employees[i] = employees[i];
    }
}

ErrorCode Department::addEmployee(const Employee &employee) {
    if (countOfEmployees >= capacity) {
        resize(capacity * 2);
    }

    Department old = *this;
    employees = new Employee[countOfEmployees + 1];
    copyFrom(old);

    if (!isInTheDepartment(employee)) {
        employees[countOfEmployees] = employee;
        countOfEmployees++;
        return ErrorCode::OK;
    }
    if (isInTheDepartment(employee)) {
        return ErrorCode::Duplicate;
    }
    return ErrorCode::InvalidInput; // or NotFound
}

ErrorCode Department::removeEmployee(const unsigned int id) {
    if (id >= countOfEmployees) {
        return ErrorCode::InvalidInput;
    }
    for (int i = 0; i < countOfEmployees; i++) {
        if (employees[i].getId() == id) {
            for (int j = i; j < countOfEmployees - 1; j++) {
                employees[j] = employees[j + 1];
            }
            countOfEmployees--;
            return ErrorCode::OK;
        }
    }
    return ErrorCode::Error;
}

unsigned int Department::getMaxEmployees() {
    return MAX_EMPLOYEES;
}

void Department::setName(const char *Name) {
    strcpy(this->name, Name);
}

const char *Department::getName() const {
    return this->name;
}

unsigned int Department::getCountOfEmployees() const {
    return countOfEmployees;
}

double Department::getAverageSalary() const {
    double allSalary = 0;
    for (unsigned int i = 0; i < countOfEmployees; i++) {
        allSalary += employees[i].getSalary();
    }
    return allSalary / countOfEmployees;
}

bool Department::isInTheDepartment(const Employee &employee) const {
    for (int i = 0; i < countOfEmployees; i++) {
        if (strcmp(employees[i].getName(), employee.getName()) == 0 ||
            employees[i].getId() == employee.getId()) {
            return true;
        }
    }
    return false;
}

bool Department::isInTheDepartment(unsigned int searchId) const {
    for (int i = 0; i < countOfEmployees; i++) {
        if (employees[i].getId() == searchId) {
            return true;
        }
    }
    return false;
}

void Department::printEmployees() const {
    for (int i = 0; i < countOfEmployees; i++) {
        std::cout << employees[i] << "\n";
    }
}

const Employee &Department::operator[](int index) const {
    return employees[index];
}

Employee &Department::operator[](int index) {
    return employees[index];
}

Department::operator bool() const {
    if (countOfEmployees != 0) {
        return true;
    }
    return false;
}

Department &Department::operator()(int percent) {
    for (int i = 0; i < countOfEmployees; i++) {
        employees[i].updateSalary(0.01 * percent * employees[i].getSalary());
    }
    return *this;
}

// void Department::print() const {
//     std::print("Department: {}\n", getName());
//     // std::print("{}", getName());
//     for (int i = 0; i < getCountOfEmployees(); i++) {
//         std::print("{}. {} \n", employees[i].getId(), employees[i].getName());
//     }
// }

std::ostream &operator<<(std::ostream &os, const Department &department) {
    os << "Department " << department.getName() << " has " << department.getCountOfEmployees() << " employees:\n";
    department.printEmployees();
    return os;
}

std::strong_ordering operator<=>(const Department &lhs, const Department &rhs) {
    if (lhs.getCountOfEmployees() != rhs.getCountOfEmployees()) {
        return lhs.getCountOfEmployees() <=> rhs.getCountOfEmployees();
    }
    if (lhs.getAverageSalary() < rhs.getAverageSalary()) {
        return std::strong_ordering::less;
    }
    if (lhs.getAverageSalary() > rhs.getAverageSalary()) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}
