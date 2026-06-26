#pragma once
#include "Requirement.h"
#include "Student.h"
class minCreditsRequirement : public Requirement
{
	private:
		unsigned int minCredits;

	public:
		minCreditsRequirement(unsigned int inpMinCredits);
		std::optional<std::string> check(const Student& s) const override;
		std::unique_ptr<Requirement> clone() const override;
};

