#include "Student.h"

Student::Student(std::string n, unsigned f, int c) : name(n), fn(f), course(c) {}

void Student::print() const {
    std::cout << "Name: " << name << " | FN: " << fn << " | Course: " << course << std::endl;
}