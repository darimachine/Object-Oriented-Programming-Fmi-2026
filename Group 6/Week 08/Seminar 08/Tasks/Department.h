#pragma once
#include "Employee.h"

class Department {
    char* name_;
    Employee* employees_;
    unsigned countOfEmployees_;
    unsigned capacity_=128;
    void moveFrom(Department&& other) noexcept;
    void resize();
    void free();
public:
    Department();
    ~Department();
    Department(Department&& other) noexcept ;
    Department& operator=(Department&& other) noexcept;
    Department(const char* name, unsigned capacity);
    ErrorCode addEmployee(const Employee &employee);
    ErrorCode removeEmployee(unsigned id);
    unsigned getCapacity() const;
    const char* getName()const;
    unsigned getEmployeesCount() const;
    bool isEmpty()const;
    double averageSalary()const;
    bool operator<(const Department &depart)const;
    bool operator>(const Department &depart)const;
    Employee& operator[]( int index);
    const Employee& operator[](int index) const;
    explicit operator bool() const;
    Department& operator()(double percent );
    friend std::ostream& operator<<(std:: ostream& os,const Department& department);
};

std::ostream& operator<<(std:: ostream& os,const Department& department);