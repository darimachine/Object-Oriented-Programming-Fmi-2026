#pragma once
#include "Discipline.h"
#include "Requirement.h"
#include "Student.h"
#include <vector>
#include <optional>
class takenDisciplinesRequirement : public Requirement
{
	private:
		std::vector<std::string> requiredDisciplines;

	public:
		takenDisciplinesRequirement(const std::vector<std::string>& inpRequiredDisciplines);
		std::optional<std::string> check(const Student& s) const override;
		std::unique_ptr<Requirement> clone() const override;
};

