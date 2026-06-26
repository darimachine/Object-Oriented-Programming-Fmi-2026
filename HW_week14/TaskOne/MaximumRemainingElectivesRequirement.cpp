#include "MaximumRemainingElectivesRequirement.h"
#include "Utils.h"

MaximumRemainingElectivesRequirement::MaximumRemainingElectivesRequirement(int totalRequired, int maxRemaining) : totalRequired(totalRequired), maxRemaining(maxRemaining)
{

}

MaximumRemainingElectivesRequirement* MaximumRemainingElectivesRequirement::clone() const
{
	return new MaximumRemainingElectivesRequirement(*this);
}

RequirementCheckResult MaximumRemainingElectivesRequirement::check(const Student& student) const
{
    int passed = 0;
    for (const auto& course : student.getPassedCourses())
    {
        if (!course.isMandatory())
        {
            passed++;
        }
    }
    int remaining = totalRequired - passed;
    if (remaining < 0)
    {
        remaining = 0;
    }
    RequirementCheckResult result;
    if (remaining <= maxRemaining)
    {
        result.passed = true;
        result.message = "";
        return result;
    }
    result.passed = false;
    result.message = "Student still has ";
    result.message += formatDouble(remaining);
    result.message += " remaining elective courses left to pass.";
    return result;
}

