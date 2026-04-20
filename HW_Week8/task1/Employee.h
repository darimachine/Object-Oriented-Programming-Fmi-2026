#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <ostream>
#include <compare>

enum class ErrorCode 
{
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full,
    OutOfRange
};

class Employee
{
private:
    static const int MAX_SIZE = 128;
	unsigned id;
	char name[MAX_SIZE];
	char position[MAX_SIZE];
	double salary;

    static unsigned lastId;

public:
    Employee();
    Employee(const char* name, const char* position, double salary);
    unsigned getId() const;
    double getSalary() const;
    const char* getName() const;
    const char* getPosition() const;

    ErrorCode updateSalary(double amount);

    static unsigned getLastId();

    Employee& operator++();
    Employee operator++(int dummy);

    std::partial_ordering operator<=>(const Employee& other) const;
    bool operator==(const Employee& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& e);
};

