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
private:

    const static int MAX_STRING_LEN = 128;
    const static double _DEFAULT_SALARY;
    const static char _DEFAULT_NAME[MAX_STRING_LEN];
    const static char _DEFAULT_POSITION[MAX_STRING_LEN];

    static unsigned int id;
    unsigned int employeeId=0;
    char name[MAX_STRING_LEN]="";
    char position[MAX_STRING_LEN]="";
    double salary = 0;

public:
    unsigned int getId();
    Employee();
    Employee(const char _name[MAX_STRING_LEN],const char _position[MAX_STRING_LEN], const double _salary);
    const char* getName() const;
    void setName(const char* newName);
    const char* getPosition() const;
    void setPosition(const char* newPosition);


    double getSalary() const;
    ErrorCode updateSalary(double amount);
    unsigned int lastEmployeeid();

    Employee& operator++();

    Employee operator++(int);
    bool operator==(const Employee& other) const;

    std::strong_ordering operator<=>(const Employee& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
    friend std::istream& operator>>(std::istream& is, Employee& e);
};

