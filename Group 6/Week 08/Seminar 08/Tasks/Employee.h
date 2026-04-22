#pragma once
#include<iostream>
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput,
    Full
};

constexpr unsigned MAX_SIZE_NAME= 127;

class Employee {
    unsigned id_;
    char name_[MAX_SIZE_NAME+1];
    char position_[MAX_SIZE_NAME+1];
    double salary_;
    static unsigned int idCounter_;
    void freeEmployee();
    void copyEmployee(const Employee &employee);
public:
    Employee();
    Employee(const char* name, const char* position, double salary);
    double getSalary() const;
    const char* getName() const;
    const char* getPosition() const;
    ErrorCode updateSalary(double amount);
    unsigned getId() const;
    static unsigned returnLastId();
    Employee& operator=(const Employee& employee);
    bool operator<(const Employee& employee) const;
    bool operator>(const Employee& employee) const;
    Employee& operator++();
    Employee operator++(int dump);
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);
};
std::ostream& operator<<(std::ostream& os, const Employee& employee);