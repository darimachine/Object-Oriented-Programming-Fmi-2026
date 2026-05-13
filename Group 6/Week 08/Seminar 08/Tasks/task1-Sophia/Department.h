#pragma once
#include "Employee.h"

class Department {
private:
    char* name;
    Employee* employees;
    unsigned countOfEmployees;
    unsigned capacity;

    void copyFrom(const Department& other);
    void free();
    void resize();

public:
    Department();
    Department(const char* name, unsigned initialCapacity = 2);
    
    Department(const Department& other);
    Department& operator=(const Department& other);
    ~Department();

    const char* getName() const;
    ErrorCode addEmployee(const Employee& e);
    ErrorCode removeEmployee(unsigned id);
    double getAverageSalary() const;

    friend std::ostream& operator<<(std::ostream& os, const Department& d);
    bool operator>(const Department& other) const;
    Employee& operator[](unsigned index);
    const Employee& operator[](unsigned index) const;
    operator bool() const;
    Department& operator()(double percentage);
};