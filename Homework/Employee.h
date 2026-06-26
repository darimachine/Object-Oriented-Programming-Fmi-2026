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
class Employee
{
    static unsigned int id;
    char name[128] = "Ivan";
    char position[128] = "No pos";
    double salary;
public:
    Employee();
    Employee(char* name, char* position, double salary);
    double getSalary() const;
    ErrorCode updateSalary(double amount);
    static int getID();
    void const print();
    std::strong_ordering operator<=>(Employee other);
    bool operator == (const Employee& other) const;
    bool operator<(const Employee& other) const;
    Employee& operator++();
    Employee& operator++(int dummy);


};

