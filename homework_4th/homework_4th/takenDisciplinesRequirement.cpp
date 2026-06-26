#include "takenDisciplinesRequirement.h"

takenDisciplinesRequirement::takenDisciplinesRequirement(const std::vector<std::string>& inpRequiredDisciplines):
	requiredDisciplines(inpRequiredDisciplines)
{
}

std::optional<std::string> takenDisciplinesRequirement::check(const Student& s) const
{
	const auto& taken = s.getTakenDisciplines();

	for (const std::string& requiredS : requiredDisciplines)
	{
		bool isTaken = false;

		for (const Discipline& currD : taken)
		{
			std::string currTakenDisc = currD.getName();
			if (currTakenDisc == requiredS)
			{
				isTaken = true;
			}
		}
		if (!isTaken)
		{
			return "The student has not taken a required discipline";
		}
	}
	return std::nullopt;
}

std::unique_ptr<Requirement> takenDisciplinesRequirement::clone() const
{
	return std::make_unique<takenDisciplinesRequirement>(*this);
}
