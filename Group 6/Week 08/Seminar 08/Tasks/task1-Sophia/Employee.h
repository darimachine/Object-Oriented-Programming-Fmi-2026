#pragma once
#include <iostream>

enum class ErrorCode {
    OK, NotFound, Duplicate, InvalidInput, Full
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

    unsigned getId() const;
    double getSalary() const;
    ErrorCode updateSalary(double amount);
    static unsigned getLastId();

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    bool operator>(const Employee& other) const;
    
    Employee& operator++();
    Employee operator++(int);
};