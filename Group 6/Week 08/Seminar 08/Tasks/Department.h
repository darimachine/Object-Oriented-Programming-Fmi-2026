#pragma once
#include "Employee.h"

class Department {
private:
    char* name{};
    Employee* employees{};
    unsigned countOfEmployees{};
    unsigned capacity{};

    void free();
    void copyFrom(const Department& other);
    void resize();

public:
    Department();
    Department(const char* name, unsigned initialCount);

    ErrorCode addEmployee(const Employee& emp);
    ErrorCode removeEmployee(unsigned id);

    Department(const Department& other);
    Department& operator=(const Department& other);
    ~Department();

    unsigned getCount() const;
    unsigned salaryAverage() const;
    const char* getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Department& dep);
    std::strong_ordering operator<=>(const Department& other) const;
    Employee& operator[](unsigned index);
    const Employee& operator[](unsigned index) const;

    //bool isDepActive() const;
    explicit operator bool() const;

    Department& operator()(double percent);
};
