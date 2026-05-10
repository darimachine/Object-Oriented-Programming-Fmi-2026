#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <compare>
#include <cstring>
#include <fstream>

enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full,
    Unauthorized
};

class Employee {
private:
    static unsigned nextId;
    unsigned id;
    char name[128];
    char position[128];
    double salary;

public:
    Employee();
    Employee(const char* name, const char* position, double salary);
    double getSalary() const;
    ErrorCode updateSalary(double amount);
    unsigned getId() const;
    static unsigned getLastInitializedId();
    void setSalary(double salary);
    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    std::strong_ordering operator<=>(const Employee& other) const;
    bool operator==(const Employee& other);
    Employee& operator++();
    Employee operator++(int);
};

class Department {
private:
    char* name;
    Employee* employees;
    unsigned countOfEmployees;
    unsigned capacity;
    void copyFrom(const Department& other);
    void free();

public:
    Department();
    Department(const char* name, int capacity);
    Department(const Department& other);
    ~Department();
    Department(Department&& other) noexcept;
    Department& operator=(const Department& other);
    Department& operator=(Department&& other) noexcept;
    void resize(unsigned newCapacity);
    ErrorCode addEmployee(const Employee& other);
    void remove(int index);
    ErrorCode removeEmployee(unsigned id);
    friend std::ostream& operator<<(std::ostream& os, const Department& d);
    double salary(const Department& d) const;
    bool operator==(const Department& other);
    std::strong_ordering operator<=>(const Department& other) const;
    Employee& operator[](int index);
    const Employee& operator[](const int index) const;
    explicit operator bool() const;
    Department& operator()(double precentage);
    void setName(const char* name);
    char* getName() const;
};

class Company {
private:
    Department departments[10];
    unsigned countOfDepartments;
    Company(const Company& other) = delete;
    Company& operator=(const Company& other) = delete;
    Company(Company&& other) = delete;
    Company& operator=(Company&& other) = delete;
    Company();

public:
    static Company& getInstance();
    ErrorCode addDepartment(const char* name);
    void remove(int index);
    ErrorCode removeDepartment(const char* name);
    ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
    friend std::ostream& operator<<(std::ostream& os, const Company& c);
    explicit operator bool() const;
    Department* operator[](const char* name);
};