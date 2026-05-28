#include "AdmissionRequirement.h"
#include "Exceptions.h"
#include "Student.h"

MinimumCreditsRequirement::MinimumCreditsRequirement(int credits) : minCredits(credits) {
	if (credits < 0) {
		throw InvalidRequirementException("Minimum credits cannot be negative.");
}
}

std::unique_ptr<AdmissionRequirement> MinimumCreditsRequirement::clone() const
{
	return std::make_unique<MinimumCreditsRequirement>(*this);
}

RequirementCheckResult MinimumCreditsRequirement::check(const Student& student) const
{
	RequirementCheckResult result;
	if (student.accumulatedCredits < minCredits) {
		result.addReason("Student has " + std::to_string(student.accumulatedCredits) 
		+ " credits, but " + std::to_string(minCredits) + " are required");
	}
	return result;
}

MinimumAverageGradeRequirement::MinimumAverageGradeRequirement(int minAvgGrade) : minAvgGrade(minAvgGrade) {
	if (minAvgGrade < 2.00 || minAvgGrade > 6.00 ) {
		throw InvalidRequirementException("Minimum average grade must be between 2 and 6.");
	}
}

std::unique_ptr<AdmissionRequirement> MinimumAverageGradeRequirement::clone() const
{
	return std::make_unique< MinimumAverageGradeRequirement>(*this);
}

RequirementCheckResult MinimumAverageGradeRequirement::check(const Student& student) const
{
	 RequirementCheckResult result;
	 if (student.avgGrade < minAvgGrade) {
		 char buffer[50];
		 snprintf(buffer, sizeof(buffer), "Student average grade is %.2f, but at least %.2f is required.", student.avgGrade, minAvgGrade);
		 result.addReason(std::string(buffer));
		 }
		 return result;
}

MinimumCoursesFromCategoryRequirement::MinimumCoursesFromCategoryRequirement(CourseCategory cat, int count) : category(cat), minCount(count)
{
	if (count < 0) {
		throw InvalidRequirementException("Course count cannot be negative.");
}
}

std::unique_ptr<AdmissionRequirement> MinimumCoursesFromCategoryRequirement::clone() const
{
	return std::make_unique< MinimumCoursesFromCategoryRequirement>(*this);
}

RequirementCheckResult MinimumCoursesFromCategoryRequirement::check(const Student& student) const
{
	 RequirementCheckResult result;
	 int count = 0;
	 for (const auto& course : student.passedCourses) {
		 if (course.category == category) {
			 count ++;
		 }
	 }
	 if (count < minCount) {
		 result.addReason("Student passed " + std::to_string(count) + " courses from category "  +
			 to_string(category) + ", but at least " + std::to_string(minCount) + " are required.");
	 } return result;
}
