#include "MinimumCreditsRequirement.h"
#include "Utils.h"

MinimumCreditsRequirement::MinimumCreditsRequirement(int minCredits) : minCredits(minCredits)
{

}

MinimumCreditsRequirement* MinimumCreditsRequirement::clone() const
{
	return new MinimumCreditsRequirement(*this);
}

RequirementCheckResult MinimumCreditsRequirement::check(const Student& student) const
{
    RequirementCheckResult result;
    if (student.getTotalCredits() >= minCredits)
    {
        result.passed = true;
        result.message = "";
        return result;
    }
    result.passed = false;
    result.message = "Student has ";
    result.message += formatDouble(student.getTotalCredits());
    result.message += " credits, but at least ";
    result.message += formatDouble(minCredits);
    result.message += " are required.";
    return result;
}

