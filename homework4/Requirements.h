#pragma once
#include "AdmissionRequirement.h"
#include <string>
#include <vector>

class MinimumCreditsRequirement : public AdmissionRequirement {
	int minCredits;

public:
	explicit MinimumCreditsRequirement(int) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class RequiredCoursesByNameRequirement : public AdmissionRequirement {
	std::vector<std::string> requiredCourses;

public:
	explicit RequiredCoursesByNameRequirement(std::vector<std::string>) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class MinimumCoursesFromCategoryRequirement : public AdmissionRequirement {
	int minCount;
	CourseCategory category;

public:
	explicit MinimumCoursesFromCategoryRequirement(int, CourseCategory) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class MinimumElectiveCreditsRequirement : public AdmissionRequirement {
	int minCredits;

public:
	explicit MinimumElectiveCreditsRequirement(int) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class MaxRemainingElectiveCoursesRequirement : public AdmissionRequirement {
	int totalElectives;
	int maxCount;

public:
	explicit MaxRemainingElectiveCoursesRequirement(int, int) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class MinimumAverageGradeRequirement : public AdmissionRequirement {
	double minGrade;

public:
	explicit MinimumAverageGradeRequirement(double) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};

class NoFailedMandatoryCoursesRequirement : public AdmissionRequirement {
	std::vector<Course> allMandatories;
public:
	explicit NoFailedMandatoryCoursesRequirement(std::vector<Course>) noexcept;
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student&) const override;
};
