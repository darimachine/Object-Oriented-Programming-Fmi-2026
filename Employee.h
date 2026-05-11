#pragma once
#include <iostream>
#include <compare>
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full
};
class Employee {
    static const int MAX_SIZE = 128;
    static unsigned idCount;
    unsigned id;
    char name[MAX_SIZE];
    char position[MAX_SIZE];
    double salary;
public:
    Employee();
    Employee(const char* name, const char* position, double salary);
    void setName(const char* name);
    void setPosition(const char* position);
    void setSalary(double salary);
    double getSalary() const;
    ErrorCode updateSalary(double amount);
    unsigned getIndividualId()const;
    static unsigned getId();
    Employee operator++(int dummy);
    Employee& operator++(); 
    friend std::ostream& operator<<(std::ostream& os, const Employee& v);
    std::partial_ordering operator<=>(const Employee& other) const;
};
