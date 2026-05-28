#pragma once
#include "RequirementCheckResult.h"
#include "CourseCategory.h"

struct Student;

class AdmissionRequirement {
	public:
	virtual ~AdmissionRequirement() = default;
	virtual std::unique_ptr<AdmissionRequirement> clone() const = 0;
	virtual RequirementCheckResult check(const Student& studentr) const = 0;
};

class MinimumCreditsRequirement : public AdmissionRequirement {
	private:
	int minCredits;
	public:
	explicit MinimumCreditsRequirement(int credits);
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student& student) const override;
};

class MinimumAverageGradeRequirement : public AdmissionRequirement {
	private:
		double minAvgGrade;
		public:
			explicit MinimumAverageGradeRequirement(int minAvgGrade);
			std::unique_ptr<AdmissionRequirement> clone() const override;
			RequirementCheckResult check(const Student& student) const override;
};

class MinimumCoursesFromCategoryRequirement : public AdmissionRequirement {
private:
	CourseCategory category;
	int minCount;
public:
	MinimumCoursesFromCategoryRequirement(CourseCategory cat, int count);
	std::unique_ptr<AdmissionRequirement> clone() const override;
	RequirementCheckResult check(const Student& student) const override;
};