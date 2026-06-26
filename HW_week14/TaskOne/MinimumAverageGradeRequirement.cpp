#include "MinimumAverageGradeRequirement.h"
#include "Utils.h"

MinimumAverageGradeRequirement::MinimumAverageGradeRequirement(double minGrade) : minGrade(minGrade)
{

}

MinimumAverageGradeRequirement* MinimumAverageGradeRequirement::clone() const
{
	return new MinimumAverageGradeRequirement(*this);
}

RequirementCheckResult MinimumAverageGradeRequirement::check(const Student& student) const
{
    RequirementCheckResult result;

    double grade = student.getAverageGrade();

    if (grade >= minGrade)
    {
        result.passed = true;
        result.message = "";
        return result;
    }

    result.passed = false;

    result.message = "Student average grade is ";
    result.message += formatDouble(grade);

    result.message += ", but at least ";
    result.message += formatDouble(minGrade);
    result.message += " is required.";

    return result;
}

