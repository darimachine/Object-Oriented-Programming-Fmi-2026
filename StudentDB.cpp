#include "StudentDB.h"
#include <iostream>

void StudentDB::add(std::string n, unsigned int f, int c) {
    students.push_back(Student(n, f, c));
}

void StudentDB::remove(unsigned int f) {
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getFn() == f) {
            students.erase(students.begin() + i);
            return;
        }
    }
}

void StudentDB::find(unsigned int f) {
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getFn() == f) {
            std::cout << "Found: " << students[i].getName() << std::endl;
            return;
        }
    }
    std::cout << "Not found." << std::endl;
}

void StudentDB::display() {
    for (int i = 0; i < (int)students.size(); i++) {
        students[i].print();
    }
}