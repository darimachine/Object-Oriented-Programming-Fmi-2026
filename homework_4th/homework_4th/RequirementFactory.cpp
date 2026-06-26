#include "RequirementFactory.h"

std::unique_ptr<Requirement> RequirementFactory::createMinimumCredits(unsigned int credits)
{
    return std::make_unique<minCreditsRequirement>(credits);
}

std::unique_ptr<Requirement> RequirementFactory::createMinimumAverageGrade(double grade)
{
	if (grade < MIN_AVG_GRADE || grade > MAX_AVG_GRADE)
	{
		throw std::invalid_argument("The inputed average grade is invalid");
	}
}

std::unique_ptr<Requirement> RequirementFactory::createminimumCategory(Category cat, unsigned int count)
{
	return std::make_unique<takenDisciplinesRequirement>(cat, count);
}

std::unique_ptr<Requirement> RequirementFactory::createMinimumCreditsChoosenDisc(unsigned int credits)
{
	return std::make_unique<minChoosenDisciplineCreditsRequirement>(credits);
}

std::unique_ptr<Requirement> RequirementFactory::createTakenDisciplines(std::vector<std::string> requiredDisciplines)
{
	return std::make_unique<Requirement>(requiredDisciplines);
}
