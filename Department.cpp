
#include "Department.h"
#include <compare>
#include <iostream>

namespace {
    void deepCopyString(char*& dest, const char* src) {
        if (!src) {
            dest = nullptr;
            return;
        }

        dest = new char[strlen(src) + 1];
        strcpy(dest, src);
    }
}

void Department::free()
{
    delete[] name;
    name = nullptr;

    delete[] employees;
    employees = nullptr;

    countOfEmployees = 0;
    capacity = 0;
}

void Department::copyFrom(const Department& other)
{
    deepCopyString(name, other.name);

    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;

    if (capacity == 0)
        capacity = 1;

    employees = new Employee[capacity];

    for (unsigned i = 0; i < countOfEmployees; i++) {
        employees[i] = other.employees[i];
    }
}

void Department::moveFrom(Department&& other) noexcept
{
    name = other.name;
    employees = other.employees;
    countOfEmployees = other.countOfEmployees;
    capacity = other.capacity;

    other.name = nullptr;
    other.employees = nullptr;
    other.countOfEmployees = 0;
    other.capacity = 0;
}

void Department::resize()
{
    unsigned newCapacity = (capacity == 0) ? 1 : capacity * 2;

    Employee* temp = new Employee[newCapacity];

    for (unsigned i = 0; i < countOfEmployees; i++) {
        temp[i] = employees[i];
    }

    delete[] employees;
    employees = temp;
    capacity = newCapacity;
}

Department::Department()
    : Department("Unknown", 1)
{
}

Department::Department(const char* name, unsigned capacity)
    : capacity(capacity)
{
    deepCopyString(this->name, name);

    if (this->capacity == 0)
        this->capacity = 1;

    employees = new Employee[this->capacity];
    countOfEmployees = 0;
}

Department::Department(const Department& other)
{
    copyFrom(other);
}

Department& Department::operator=(const Department& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Department::Department(Department&& other) noexcept
{
    moveFrom(std::move(other));
}

Department& Department::operator=(Department&& other) noexcept
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Department::~Department()
{
    free();
}

const char* Department::getName() const
{
    return name;
}

ErrorCode Department::addEmployee(const Employee& other)
{
    if (countOfEmployees == capacity)
        resize();

    employees[countOfEmployees++] = other;

    return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
    int index = -1;

    for (unsigned i = 0; i < countOfEmployees; i++) {
        if (employees[i].getIndividualId() == id) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return ErrorCode::NotFound;

    for (unsigned i = index; i < countOfEmployees - 1; i++) {
        employees[i] = employees[i + 1];
    }
    employees[countOfEmployees - 1] = Employee();
    countOfEmployees--;

    return ErrorCode::OK;
}

Department& Department::operator()(unsigned percent)
{
    for (unsigned i = 0; i < countOfEmployees; i++) {
        employees[i].updateSalary(
            employees[i].getSalary() * percent / 100.0
        );
    }
    return *this;
}

double Department::getAvgSalary() const
{
    if (countOfEmployees == 0)
        return 0;

    double sum = 0;

    for (unsigned i = 0; i < countOfEmployees; i++) {
        sum += employees[i].getSalary();
    }

    return sum / countOfEmployees;
}

std::partial_ordering Department::operator<=>(const Department& other) const
{
    if (countOfEmployees == other.countOfEmployees) {
        return getAvgSalary() <=> other.getAvgSalary();
    }

    return countOfEmployees <=> other.countOfEmployees;
}

std::ostream& operator<<(std::ostream& os, const Department& d)
{
    os << d.name << "\n";

    for (unsigned i = 0; i < d.countOfEmployees; i++) {
        os << d.employees[i] << "\n";
    }

    return os;
}

Employee& Department::operator[](size_t index)
{
    return employees[index];
}

const Employee& Department::operator[](size_t index) const
{
    return employees[index];
}

Department::operator bool() const
{
    return countOfEmployees > 0;
}