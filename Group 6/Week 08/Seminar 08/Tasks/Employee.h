#pragma once
#include <iostream>
#include "ErrorCode.h"

constexpr int MAX_SIZE = 127;

class Employee {
private:
    unsigned id{};
    char name[MAX_SIZE + 1]{};
    char position[MAX_SIZE + 1]{};
    double salary{};

    static unsigned lastID;
    static unsigned nextID();

public:
    Employee();
    Employee(const char* name, const char* position, double salary);

    double getSalary() const;
    unsigned getId() const;
    ErrorCode updateSalary(double amount);

    static unsigned getLastID();

    friend std::ostream& operator<<(std::ostream& os, const Employee& emp);

    std::strong_ordering operator<=>(const Employee& other) const;

    Employee& operator++();
    Employee operator++(int dummy);
};