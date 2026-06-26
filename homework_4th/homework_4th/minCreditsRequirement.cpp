#include "minCreditsRequirement.h"

minCreditsRequirement::minCreditsRequirement(unsigned int inpMinCredits) : minCredits(inpMinCredits)
{
}

std::optional<std::string> minCreditsRequirement::check(const Student& s) const
{
	if (s.getTotalCredits() < minCredits)
	{
		return "Student does not have the minimum credits";
	}
	return std::nullopt;
}

std::unique_ptr<Requirement> minCreditsRequirement::clone() const
{
	return std::make_unique<minCreditsRequirement>(*this);
}
