#pragma once
#include "Requirement.h"
#include "Category.h"
class MinCategoryDisciplinesRequirement : public Requirement
{
	private:
		Category targetCategory;
		unsigned int minRequiredCount;

	public:
		MinCategoryDisciplinesRequirement(Category cat, unsigned int count);
		std::optional<std::string> check(const Student& s) const override;
		std::unique_ptr<Requirement> clone() const override;
};

