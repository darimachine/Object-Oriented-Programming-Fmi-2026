#pragma once
#include "takenDisciplinesRequirement.h"
#include "MinCategoryDisciplinesRequirement.h"
#include "minChoosenDisciplineCreditsRequirement.h"
#include "minCreditsRequirement.h"
#include "minGradeRequirement.h"
#include "takenDisciplinesRequirement.h"
#include <stdexcept>
#include <memory>
class RequirementFactory
{
	public:
		static std::unique_ptr<Requirement> createMinimumCredits(unsigned int credits);
		static std::unique_ptr<Requirement> createMinimumAverageGrade(double grade);
		static std::unique_ptr<Requirement> createminimumCategory(Category cat, unsigned int count);
		static std::unique_ptr<Requirement> createMinimumCreditsChoosenDisc(unsigned int credits);
		static std::unique_ptr<Requirement> createTakenDisciplines(std::vector<std::string> requiredDisciplines);

};

