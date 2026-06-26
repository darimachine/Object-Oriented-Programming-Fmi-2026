#include "minGradeRequirement.h"

minGradeRequirement::minGradeRequirement(double inpMinAvgGrade) : minAvgGrade(inpMinAvgGrade)
{
}

std::optional<std::string> minGradeRequirement::check(const Student& s) const
{
	if (s.getAverageGrade() < minAvgGrade)
	{
		return "The student does not have the minimum average grade";
	}
	return std::nullopt;
}

std::unique_ptr<Requirement> minGradeRequirement::clone() const
{
	return std::make_unique<minGradeRequirement>(*this);
}
