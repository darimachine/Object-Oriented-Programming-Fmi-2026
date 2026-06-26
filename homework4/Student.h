#pragma once
#include "Course.h"
#include <string>
#include <vector>

class Student {
	std::string facultyNumber;
	std::string name;
	std::vector<Course> passedCourses;
	int totalCredits;
	double averageGrade;

public:
	explicit Student(std::string, std::string, std::vector<Course>, int, double);
	const std::string& getFacultyNumber() const;
	const std::string& getName() const;
	const std::vector<Course>& getPassedCourses() const;
	int getTotalCredits() const;
	double getAverageGrade() const;
};
