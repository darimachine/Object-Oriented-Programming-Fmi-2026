#pragma once
#include <string>
#include "Category.h"
class Discipline
{
	private:
		std::string name;
		unsigned int credits;
		bool isRequired;
		Category currCategory;

	public:
		Discipline(const std::string& inpName, unsigned int inpCredits, bool inpIsRequired, Category inpCat);
		const std::string& getName() const;
		 std::string getCategoryAsString() const;
		 Category getCategory() const;
};

