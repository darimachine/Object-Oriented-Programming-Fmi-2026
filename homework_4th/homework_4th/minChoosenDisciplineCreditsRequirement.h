#pragma once
#include "Discipline.h"
#include "Requirement.h"
#include "Student.h"
#include <vector>
#include <optional>
class minChoosenDisciplineCreditsRequirement : public Requirement
{
	private:
		unsigned int minCDiscCredits;

	public:
		minChoosenDisciplineCreditsRequirement(unsigned int inpMin);
		std::optional<std::string> check(const Student& s) const override;

};

