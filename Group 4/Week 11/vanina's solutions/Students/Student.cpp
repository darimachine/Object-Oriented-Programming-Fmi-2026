//
// Created by Vanina Laleva on 29.04.26.
//

#include "Student.h"

Student::Student() {
    name = "no name";
    course = 0;
    fNumber = 0;
}

Student::Student(const std::string &name, unsigned fNumb, int course) :
                name(name), fNumber(fNumb), course(course) { }

unsigned Student::getFNumb() const {
    return fNumber;
}

const std::string & Student::getName() const {
    return name;
}

int Student::getCourse() const {
    return course;
}

void Student::print() const {
    std::cout << name << ": " << fNumber << " - " << course << " course" << std::endl;
}
