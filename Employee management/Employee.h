#pragma once
#include <iostream>
#include <functional>
#include <compare>
const int SIZE = 128;
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full
};
class Employee
{
private:
    static unsigned br;
    unsigned id;
    char name[SIZE];
    char position[SIZE];
    mutable double salary;
public:
    Employee();
    Employee(char* n,char* p, double s);
    double getSalary() const;
    ErrorCode updateSalary(double amount);
    static unsigned ReturnID();
    friend std::ostream& operator<<(std::ostream& out, const Employee& E);
    Employee& operator++();
    Employee operator++(int prefix);

};
bool operator<(const Employee& D1, const Employee& D2);
bool operator>(const Employee& D1, const Employee& D2);
bool operator==(const Employee& D1, const Employee& D2);
