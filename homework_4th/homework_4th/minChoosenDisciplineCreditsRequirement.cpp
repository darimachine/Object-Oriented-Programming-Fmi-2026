#include "minChoosenDisciplineCreditsRequirement.h"

minChoosenDisciplineCreditsRequirement::minChoosenDisciplineCreditsRequirement(unsigned int inpMin) : minCDiscCredits(inpMin)
{
}

std::optional<std::string> minChoosenDisciplineCreditsRequirement::check(const Student& s) const
{
	if (s.getChoosenDiscCredits() < minCDiscCredits)
	{
		return "The student does not have the minimum of credits for choosen discipline";
	}
	return std::nullopt;
}
