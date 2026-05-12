//
// Created by Boris Bozhilov on 4/13/2026.
//

#include "Department.h"

#include <cmath>
#include <utility>
#include <iostream>

// utility functions
bool Department::isValid() const {

    if (name == nullptr) return false;
    if (name[0] == '\0') return false;
    if (employees == nullptr) return false;
    if (capacity <= 0) return false;
    if (countOfEmployees < 0) return false;
    if (countOfEmployees > capacity) return false;

    return true;
}

Utils::ErrorCode Department::findEmployeeInArray(const unsigned int employeeID, unsigned int &employeeIndex) const {

    for (int i = 0; i < countOfEmployees; i++) {

        if (employees[i].getID() == employeeID) {

            employeeIndex = i;
            return Utils::ErrorCode::OK;
        }
    }

    return Utils::ErrorCode::NotFound;
}

double Department::getAverageSalaryOfDepartment() const {

    double averageSalary = 0;

    for (unsigned int i = 0; i < countOfEmployees; i++) {

        averageSalary += employees[i].getSalary();
    }

    averageSalary /= countOfEmployees;

    return averageSalary;
}

const char* Department::getName() const {

    return name;
}

bool Department::hasNoMoreCapacity() const {

    return countOfEmployees >= capacity;
}

void Department::copyDepartmentDataFromOther(const Department &other) {

    Utils::copyString(other.name, name);
    Employee::copyArrayOfEmployees(other.employees, other.countOfEmployees, employees);
    capacity = other.capacity;
    countOfEmployees = other.countOfEmployees;
}

void Department::moveDepartmentDataFromOther(Department &&other) {

    Utils::moveString(other.name, name);
    Employee::moveArrayOfEmployees(other.employees, employees);
    capacity = other.capacity;
    countOfEmployees = other.countOfEmployees;
}

// rule of 5
Department::Department() = default;

Department::Department(const char *name, const unsigned int capacity){

    if (name == nullptr) return;
    if (name[0] == '\0') return;

    countOfEmployees = 0;
    this->capacity = capacity;
    Utils::copyString(name, this->name);
    employees = new Employee[capacity];
}

Department::Department(const Department &other) {

    if (!other.isValid()) return;

    copyDepartmentDataFromOther(other);
}

Department &Department::operator=(const Department &other) {

    if (this == &other) return *this;

    if (!other.isValid()) return *this;

    copyDepartmentDataFromOther(other);

    return *this;
}

Department::Department(Department &&other) noexcept {

    // we want to forbid taking the other object's invalid data, so we set it to the default invalid state
    if (!other.isValid()) return;

    moveDepartmentDataFromOther(std::move(other));
}

Department &Department::operator=(Department &&other) noexcept {

    if (this == &other) return *this;

    // if the other object is invalid we don't take the invalid data
    if (!other.isValid()) return *this;

    moveDepartmentDataFromOther(std::move(other));

    return *this;
}

Department::~Department() {

    Utils::freeString(name);
    Employee::freeArrayOfEmployees(employees);
    countOfEmployees = 0;
    capacity = 0;
}

// methods
// NOTE we want to force the user to use the move semantics, so if an employee is created it must be part of a department
Utils::ErrorCode Department::addEmployee(Employee &&employee) {

    if (countOfEmployees >= capacity) return Utils::ErrorCode::Full;
    if (!employee.isValid()) return Utils::ErrorCode::InvalidInput;

    employees[countOfEmployees++] = std::move(employee);

    return Utils::ErrorCode::OK;
}

Utils::ErrorCode Department::removeEmployee(const unsigned int employeeID) {

    unsigned int employeeIndex = 0;

    if (findEmployeeInArray(employeeID, employeeIndex) == Utils::ErrorCode::NotFound)
        return Utils::ErrorCode::NotFound;

    for (unsigned int i = employeeIndex + 1; i < countOfEmployees; i++) {

        employees[i - 1] = std::move(employees[i]);
    }

    countOfEmployees--;

    return Utils::ErrorCode::OK;
}

// operators
bool Department::operator==(const Department &other) const {

    if (this == &other) return true;

    if (countOfEmployees != other.countOfEmployees) return false;
    if (std::abs(getAverageSalaryOfDepartment() - other.getAverageSalaryOfDepartment()) < Utils::EPSILON) return true;

    return false;
}

std::strong_ordering Department::operator<=>(const Department &other) const {

    if ((countOfEmployees <=> other.countOfEmployees) == 0) {

        const double thisAvgSalary = getAverageSalaryOfDepartment();
        const double otherAvgSalary = other.getAverageSalaryOfDepartment();

        if (std::abs(thisAvgSalary - otherAvgSalary) < Utils::EPSILON) return std::strong_ordering::equal;
        if (thisAvgSalary < otherAvgSalary) return std::strong_ordering::less;
        return std::strong_ordering::greater;
    }

    return countOfEmployees <=> other.countOfEmployees;
}

Department& Department::operator()(const unsigned int rate) {

    for (unsigned int i = 0; i < countOfEmployees; i++) {

        const double currentSalary = employees[i].getSalary();

        // converting the rate into percent(10 becomes 1.1 and gets multiplied to the current salary)
        const double raisedSalary = currentSalary * ((rate + 100.0) / 100);

        employees[i].updateSalary(raisedSalary);
    }

    return *this;
}

Department::operator bool() const {

    return countOfEmployees != 0;
}

std::ostream &operator<<(std::ostream &output, const Department &department) {

    output << department.name << ": " << department.countOfEmployees << " employees, Capacity: "
    << department.capacity << std::endl;

    for (unsigned int i = 0; i < department.countOfEmployees; i++) {

        output << department.employees[i] << std::endl;
    }

    return output;
}


// NOTE this functionality can break the class, because it allows employees to be moved to different indexes
// NOTE in the array which can breaks the logic of assigning an employee in an index based on the countOfEmployees variable
Employee Department::operator[](const unsigned int employeeIndex) const {

    // perhaps this check can be used to bypass this problem
    // if (employeeIndex >= countOfEmployees) return Employee();

    return employees[employeeIndex];
}

Employee &Department::operator[](const unsigned int employeeIndex) {

    // additionally for the [] that returns a reference this is the temporary fix, but it can be improved
    // adding an element at the end of each employees array that is set to be invalid and being returned instead of employees[0]
    // this would make the size of the employees array = capacity + 1
    // if (employeeIndex >= countOfEmployees) return employees[0];

    return employees[employeeIndex];
}


// NOTE this is the alternative that I propose, it ensures that objects that aren't added yet cannot be reached
// NOTE thus objects on indexes after countOfEmployees cannot be accessed and changed
// Employee Department::operator[](const unsigned int employeeID) const {
//
//     unsigned int employeeIndex = 0;
//     if (findEmployeeInArray(employeeID, employeeIndex) == Utils::ErrorCode::NotFound) return Employee();
//
//     return employees[employeeIndex];
// }
//
// Employee &Department::operator[](const unsigned int employeeID) {
//
//     unsigned int employeeIndex = 0;
//
//     // the same proposal above can be used here - adding an element in the end of each array that is invalid and returned here
//     if (findEmployeeInArray(employeeID, employeeIndex) == Utils::ErrorCode::NotFound) return employees[0];
//
//     return employees[employeeIndex];
// }