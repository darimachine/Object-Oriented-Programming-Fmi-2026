#pragma once
#include <string>
#include <vector>
#include "Course.h"
class Student
{
private:
    std::string facultyNumber;
    std::string name;
    std::vector<Course> passedCourses;
    int totalCredits;
    double averageGrade;
public:
    Student(const std::string& facultyNumber, const std::string& name, int totalCredits, double averageGrade);
    void addCourse(const Course& course);
    const std::string& getFacultyNumber() const;
    const std::string& getName() const;
    const std::vector<Course>& getPassedCourses() const;
    int getTotalCredits() const;
    double getAverageGrade() const;
};

