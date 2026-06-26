#include "MinimumElectiveCreditsRequirement.h"
#include "Utils.h"

MinimumElectiveCreditsRequirement::MinimumElectiveCreditsRequirement(int minCredits) : minCredits(minCredits)
{

}

MinimumElectiveCreditsRequirement* MinimumElectiveCreditsRequirement::clone() const
{
	return new MinimumElectiveCreditsRequirement(*this);
}

RequirementCheckResult MinimumElectiveCreditsRequirement::check(const Student& student) const
{
    int credits = 0;
    for (const auto& c : student.getPassedCourses())
    {
        if (!c.isMandatory())
        {
            credits += c.getCredits();
        }
    }
    RequirementCheckResult result;
    if (credits >= minCredits)
    {
        result.passed = true;
        result.message = "";
        return result;
    }
    result.passed = false;
    result.message = "Student has ";
    result.message += formatDouble(credits);
    result.message += " credits from electives, but at least ";
    result.message += formatDouble(minCredits);
    result.message += " are required.";
    return result;
}

