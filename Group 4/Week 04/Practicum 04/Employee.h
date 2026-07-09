#pragma once
enum class ErrorCode {
    OK,
    NotFound,
    Duplicate,
    InvalidInput
};

class Employee {
    unsigned id_;
    char name_[127];
    char position_[127];
    double salary_;
    static unsigned int idCounter_;
public:
    Employee();
    Employee(const char* name, const char* position, double salary);
    double getSalary() const;
    const char* getName() const;
    ErrorCode updateSalary(double amount);
    unsigned getId() const;
};