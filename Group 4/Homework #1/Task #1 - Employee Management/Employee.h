//
// Created by Boris Bozhilov on 4/13/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EMPLOYEE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EMPLOYEE_H
#include <compare>
#include <iosfwd>

#include "Utils.h"


class Employee {

private:

    static constexpr unsigned int MAX_STRING_CAPACITY = 128;
    static constexpr double RATE_OF_SALARY_INCREASE = 0.10;

    static unsigned int countOfEmployees;

    unsigned int id = 0;
    char* name = nullptr;
    char* position = nullptr;
    double salary = -1;

    void copyEmployeeDataFromOther(const Employee& other);
    void moveEmployeeDataFromOther(Employee&& other);

public:

    // utility functions
    static void copyArrayOfEmployees(const Employee* source, const unsigned int sourceSize, Employee*& destination);
    static void freeArrayOfEmployees(Employee*& source);
    static void moveArrayOfEmployees(Employee*& source, Employee*& destination) noexcept;
    bool isValid() const;
    unsigned int getID() const;

    // rule of 5
    Employee();
    Employee(const char* name, const char* position, double salary);

    Employee(const Employee& other);
    Employee& operator=(const Employee& other);

    Employee(Employee&& other) noexcept;
    Employee& operator=(Employee&& other) noexcept;

    ~Employee();

    // methods
    double getSalary() const;
    Utils::ErrorCode updateSalary(double amount);
    static unsigned int getCountOfEmployees();
    static unsigned int getLastEmployeeID();

    // operators
    friend std::ostream& operator<<(std::ostream& output, const Employee &employee);
    bool operator==(const Employee& other) const;
    std::strong_ordering operator<=>(const Employee& other) const;
    Employee& operator++();
    Employee operator++(int);

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_EMPLOYEE_H
