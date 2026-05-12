#pragma once
#include "Student.h"
#include <vector>

class StudentDB {
protected: 
    std::vector<Student> students;

public:
    StudentDB() = default;
    virtual ~StudentDB() = default;

    void add(std::string n, unsigned int f, int c);
    void remove(unsigned int f);
    void find(unsigned int f);
    void display();
};