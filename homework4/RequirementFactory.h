#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Requirements.h"
#include "Course.h"
#include "Exceptions.h"

class RequirementFactory {
public:
	static std::unique_ptr<AdmissionRequirement> createMinimumCredits(int);
	static std::unique_ptr<AdmissionRequirement> createRequiredCoursesByName(std::vector<std::string>);
	static std::unique_ptr<AdmissionRequirement> createMinimumCoursesFromCategory(int, CourseCategory);
	static std::unique_ptr<AdmissionRequirement> createMinimumElectiveCredits(int);
	static std::unique_ptr<AdmissionRequirement> createMaxRemainingElectiveCourses(int , int);
	static std::unique_ptr<AdmissionRequirement> createMinimumAverageGrade(double);
	static std::unique_ptr<AdmissionRequirement> createNoFailedMandatoryCourses(std::vector<Course>);
};
