#pragma once
#include  "Employee.h"
#include  <compare>
#include <iostream>
class Department
{
private:
    char* name = nullptr;
    Employee *employees;
    unsigned int countOfEmployees;
    unsigned capacity;

    void resizeDeparment(unsigned);
    void copyFrom(const Department&);
    void free();

public:
    Department();
    Department(const char* inpName, unsigned);
    ~Department();
    Department(const Department&);
    Department& operator=(const Department&);
    void setDepName(const char*);
    const char* getDepName() const;
    ErrorCode addEmployee(const Employee& currEmployee);
    ErrorCode removeEmployee(unsigned int);

    void swapEmployees( Employee&,  Employee&);

    friend std::ostream& operator<<(std::ostream&, const Department&);
    std::strong_ordering operator<=>(const Department&);
    friend bool operator==(const Department&, const Department&);
    double averageSalaryDepartmnet() const;
    const Employee& operator[](unsigned) const;
    Employee& operator[](unsigned);
    operator bool() const;
    Department& operator()(double);
};

