#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"

class Department
{
private:
    char* name;
    Employee* employees;
    unsigned countOfEmployees;
    unsigned capacity;
    void copyFrom(const Department& other);
    void moveFrom(Department&& other) noexcept;
    void free();
    void resize();
    static Employee dummyEmployee;
    static const int CAP_SIZE = 4;

public:
    Department();
    Department(const char* name, unsigned initialCapacity = 4);

    Department(const Department& other);
    Department& operator=(const Department& other);
    Department(Department&& other) noexcept;
    Department& operator=(Department&& other) noexcept;
    ~Department();

    const char* getName() const;
    unsigned getCount() const;
    double averageSalary() const;

    ErrorCode addEmployee(const Employee& employee);
    ErrorCode removeEmployee(unsigned id);

    Employee& operator[](unsigned index);
    const Employee& operator[](unsigned index) const;

    Department& operator()(double percent);

    std::partial_ordering operator<=>(const Department& other) const;
    bool operator==(const Department& other) const;

    explicit operator bool() const;

    friend std::ostream& operator<<(std::ostream& os, const Department& department);
};

