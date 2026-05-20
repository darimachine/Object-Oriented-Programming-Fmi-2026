//
// Created by Vanina Laleva on 29.04.26.
//

#ifndef STUDENTS_STUDENT_H
#define STUDENTS_STUDENT_H

#include <string>
#include <iostream>

class Student {
    std::string name;
    unsigned fNumber;
    int course;

public:
    Student();
    Student(const std::string& name, unsigned fNumb, int course);

    unsigned getFNumb() const;
    const std::string& getName() const;
    int getCourse() const;

    void print() const;
};


#endif //STUDENTS_STUDENT_H