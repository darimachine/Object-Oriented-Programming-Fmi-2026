#pragma once
#include <string>
#include <vector>
#include "Course.h"

struct Student {
	std::string fn;
	std::string name;
	std::vector<Course> passedCourses;
	int accumulatedCredits;
	double avgGrade;
};
