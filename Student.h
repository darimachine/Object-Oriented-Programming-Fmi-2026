
#pragma once
#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    unsigned int fn;
    int course;

public:
    Student() = default;
    Student(std::string n, unsigned int f, int c);

    std::string getName() const { return name; }
    unsigned int getFn() const { return fn; }
    int getCourse() const { return course; }

    void print() const;
};