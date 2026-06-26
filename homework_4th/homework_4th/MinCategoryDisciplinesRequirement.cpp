#include "MinCategoryDisciplinesRequirement.h"

MinCategoryDisciplinesRequirement::MinCategoryDisciplinesRequirement(Category cat, unsigned int count):
	targetCategory(cat), minRequiredCount(count)
{
}

std::optional<std::string> MinCategoryDisciplinesRequirement::check(const Student& s) const
{
	unsigned int actualCount = 0;

    for (const auto& discipline : s.getTakenDisciplines())
    {
        if (discipline.getCategory() == targetCategory)
        {
            actualCount++;
        }
    }
    if (actualCount < minRequiredCount)
    {
        return "Insufficient category disciplines taken";
    }

    return std::nullopt;
}

std::unique_ptr<Requirement> MinCategoryDisciplinesRequirement::clone() const
{
    return std::make_unique<MinCategoryDisciplinesRequirement>(*this);
}

