#include "Discipline.h"

Discipline::Discipline(const std::string& inpName, unsigned int inpCredits,
			bool inpIsRequired, Category inpCat) 
			: name(inpName), credits(inpCredits), isRequired(inpIsRequired), currCategory(inpCat)
{
}

const std::string& Discipline::getName() const
{
	return name;
}

 std::string Discipline::getCategoryAsString() const
{
	 if (currCategory == Category::ApliedMaths)
	 {
		 return "AppliedMaths";
	}
	 else if (currCategory == Category::Maths)
	 {
		 return "Maths";
	 }
	 else
	 {
		 return "Programming";
	 }
}

 Category Discipline::getCategory() const
 {
	 return currCategory;
 }
