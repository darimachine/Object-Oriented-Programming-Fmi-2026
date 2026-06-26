#include "Student.h"

Student::Student(std::string fn, std::string n, std::vector<Course> c, int tc, double ag)
    : facultyNumber(std::move(fn)), name(std::move(n)), passedCourses(std::move(c)),
    totalCredits(tc), averageGrade(ag) {}

const std::string& Student::getFacultyNumber() const {
    return facultyNumber;
}

const std::string& Student::getName() const {
    return name;
}

const std::vector<Course>& Student::getPassedCourses() const {
    return passedCourses;
}

int Student::getTotalCredits() const {
    return totalCredits;
}

double Student::getAverageGrade() const {
    return averageGrade;
}
