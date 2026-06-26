#include "Requirements.h"

MinimumCreditsRequirement::MinimumCreditsRequirement(int minCr) noexcept : minCredits(minCr) {}

std::unique_ptr<AdmissionRequirement> MinimumCreditsRequirement::clone() const {
	return std::make_unique<MinimumCreditsRequirement>(*this);
}

RequirementCheckResult MinimumCreditsRequirement::check(const Student& s) const {
	if (s.getTotalCredits() >= minCredits)
		return RequirementCheckResult(true, "");
	else {
		return RequirementCheckResult(false,
			"Student has " + std::to_string(s.getTotalCredits()) +
			" credits, but at least " + std::to_string(minCredits) + " are required.");
	}
}

RequiredCoursesByNameRequirement::RequiredCoursesByNameRequirement(std::vector<std::string> rn) noexcept
	: requiredCourses(std::move(rn)) {}

std::unique_ptr<AdmissionRequirement> RequiredCoursesByNameRequirement::clone() const {
	return std::make_unique<RequiredCoursesByNameRequirement>(*this);
}

RequirementCheckResult RequiredCoursesByNameRequirement::check(const Student& s) const {
	std::string missing = "";
	for (const std::string& name : requiredCourses) {
		bool found = false;
		for (const Course& c : s.getPassedCourses()) {
			if (c.getName() == name)
				found = true;
		}
		if (!found)
			missing += "Required course not passed: " + name + "\n";
	}
	if (missing.empty())
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false, missing);
}

MinimumCoursesFromCategoryRequirement::MinimumCoursesFromCategoryRequirement(int minC, CourseCategory c) noexcept
	: minCount(minC), category(c) {}

std::unique_ptr<AdmissionRequirement> MinimumCoursesFromCategoryRequirement::clone() const {
	return std::make_unique<MinimumCoursesFromCategoryRequirement>(*this);
}

RequirementCheckResult MinimumCoursesFromCategoryRequirement::check(const Student& s) const {
	int count = 0;
	for (const Course& c : s.getPassedCourses()) {
		if (c.getCourseCategory() == category) {
			count++;
		}
	}
	if (count >= minCount)
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false,
			"Student has completed " + std::to_string(count) +
			" courses from the required category, but at least " + std::to_string(minCount) + " are required.");
}

MinimumElectiveCreditsRequirement::MinimumElectiveCreditsRequirement(int minCr) noexcept
	: minCredits(minCr) {}

std::unique_ptr<AdmissionRequirement> MinimumElectiveCreditsRequirement::clone() const {
	return std::make_unique<MinimumElectiveCreditsRequirement>(*this);
}

RequirementCheckResult MinimumElectiveCreditsRequirement::check(const Student& s) const {
	int electiveCredits = 0;
	for (const Course& c : s.getPassedCourses()) {
		if (!c.isMandatory()) {
			electiveCredits += c.getCredits();
		}
	}
	if (electiveCredits >= minCredits)
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false,
			"Student has " + std::to_string(electiveCredits) +
			", but at least " + std::to_string(minCredits) + " are required.");
}

MaxRemainingElectiveCoursesRequirement::MaxRemainingElectiveCoursesRequirement(int te, int maxC) noexcept
	: totalElectives(te), maxCount(maxC) {}

std::unique_ptr<AdmissionRequirement> MaxRemainingElectiveCoursesRequirement::clone() const {
	return std::make_unique<MaxRemainingElectiveCoursesRequirement>(*this);
}

RequirementCheckResult MaxRemainingElectiveCoursesRequirement::check(const Student& s) const {
	int remaining = 0;
	for (const Course& c : s.getPassedCourses()) {
		if (!c.isMandatory())
			remaining++;
	}
	int notTaken = totalElectives - remaining;
	if (notTaken <= maxCount)
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false,
			"Student still has " + std::to_string(notTaken-maxCount) +
			" remaining elective courses to pass.");
}

MinimumAverageGradeRequirement::MinimumAverageGradeRequirement(double minGr) noexcept
	: minGrade(minGr) {}

std::unique_ptr<AdmissionRequirement> MinimumAverageGradeRequirement::clone() const {
	return std::make_unique<MinimumAverageGradeRequirement>(*this);
}

RequirementCheckResult MinimumAverageGradeRequirement::check(const Student& s) const {
	if (s.getAverageGrade() >= minGrade)
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false,
			"Student's average grade is " + std::to_string(s.getAverageGrade()) +
			", but at least " + std::to_string(minGrade) + " is required.");
}

NoFailedMandatoryCoursesRequirement::NoFailedMandatoryCoursesRequirement(std::vector<Course> am) noexcept
	: allMandatories(std::move(am)) {}

std::unique_ptr<AdmissionRequirement> NoFailedMandatoryCoursesRequirement::clone() const {
	return std::make_unique<NoFailedMandatoryCoursesRequirement>(*this);
}

RequirementCheckResult NoFailedMandatoryCoursesRequirement::check(const Student& s) const {
	std::string notPassed = "";
	for (const Course& mandatory : allMandatories) {
		bool found = false;
		for (const Course& passed : s.getPassedCourses())
			if (passed.isMandatory() && passed.getName() == mandatory.getName())
				found = true;
		if (!found)
			notPassed += "Mandatory course not passed: " + mandatory.getName() + "\n";
	}
	if (notPassed.empty())
		return RequirementCheckResult(true, "");
	else
		return RequirementCheckResult(false, notPassed);
}
