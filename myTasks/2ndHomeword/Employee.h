#pragma once
#include  "ErrorCode.h"
#include  <iostream>
constexpr  int MAX_LEN_NAME = 127;
constexpr  int MIN_SALARY = 1000;

class Employee
{
private:
    static unsigned int Lastid;
    unsigned int ID;
    char name[MAX_LEN_NAME];
    char position[MAX_LEN_NAME];
    double salary;

public:
    Employee();
    Employee(const char*inpName, const char*inpPosition, double inpSalary);

    void setName(const char *inpName);
    void setPosition(const char *inpPosition);
    void setSalary(double inpSalary);

    double getSalary() const;
    ErrorCode updateSalary(double amount);
    static unsigned int getLastID();
    const char* getPosition() const;

    // void printInfoEmployee() const;
    friend std::ostream& operator<<(std::ostream&, const Employee&);
    friend  bool operator==(const Employee &, const Employee &);
    std::strong_ordering operator<=>(const Employee &) const;
    Employee& operator++();
    Employee operator++(int);

    const char *getEmployeeName() const;
    unsigned int getId() const;
    //const char* printExitCode(ErrorCode currErrorCode) const;

};



