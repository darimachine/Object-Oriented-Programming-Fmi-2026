//
// Created by Vanina Laleva on 29.04.26.
//

#include "StudentDB.h"

int StudentDB::getSize() const {
    return students.size();
}

const Student & StudentDB::operator[](int index) const {
    return students[index];
}

Student & StudentDB::operator[](int index) {
    return students[index];
}

void StudentDB::add(const Student& student) {
    students.push_back(student);
}

void StudentDB::add(const std::string &name, unsigned fNum, int course) {
    Student student(name, fNum, course);
    students.push_back(student);
}

void StudentDB::remove(unsigned fNumber) {
    int index = 0;
    for (const Student& st : students) {
        if (st.getFNumb() == fNumber) {
            students.erase(students.begin() + index);
        }
        index++;
    }
}

bool StudentDB::find(unsigned fNumber) const {
    for (const Student& st : students) {
        if (st.getFNumb() == fNumber) {
            std::cout << "Info for found student with faculty number " << fNumber << ":\n";
            st.print();
            return true;
        }
    }
    return false;
}

void StudentDB::display() const {
    for (const Student& student : students) {
        student.print();
    }
}
