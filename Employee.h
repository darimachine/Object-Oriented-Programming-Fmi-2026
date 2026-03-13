#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<print>
#include "ErrorCode.h"

class Employee
{
private:

    static constexpr int MAX_SIZE = 127;
    static constexpr double EPSILON = 0.0001;

    unsigned id;
    char name[MAX_SIZE];
    char position[MAX_SIZE];
    double salary;
    static unsigned brEmployees;

public:
    Employee();

    Employee(const char* name, const char* position, double salary);

    void setName(const char* name);

    void setPosition(const char* position);

    void setSalary(double salary);

    double getSalary()const;

    unsigned getId()const;

    ErrorCode updateSalary(double amount);

    static unsigned getIdLastEmployee();

    void printEmployee()const;
};
