#pragma once
#include <string>
class Student
{
    std::string name;
    unsigned facultyNumber;
    int year;
public:
    Student();
    Student(std::string name, unsigned facultyNumber, int year);
    unsigned getFN() const;
    std::string getName() const;
    int getYear() const;
    void display() const;
};

