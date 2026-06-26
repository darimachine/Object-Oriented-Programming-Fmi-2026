//
// Created by Vanina Laleva on 29.04.26.
//

#ifndef STUDENTS_STUDENTDB_H
#define STUDENTS_STUDENTDB_H
#include "Student.h"

#include<vector>

class StudentDB {
protected:
    std::vector<Student> students;

public:
    int getSize() const;

    const Student& operator[](int index) const;
    Student& operator[](int index);

    void add(const Student& student);
    void add(const std::string& name, unsigned fNum, int course);
    void remove(unsigned fNumber);
    bool find(unsigned fNumber) const;
    void display() const;
};


#endif //STUDENTS_STUDENTDB_H