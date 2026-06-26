#pragma once
#include "Requirement.h"
constexpr  double MIN_AVG_GRADE= 3.00;
constexpr double MAX_AVG_GRADE = 6.00;
#include <stdexcept>
class minGradeRequirement : public Requirement
{
	private:
		double minAvgGrade;

	public:
		minGradeRequirement(double inpMinAvgGrade);

		std::optional<std::string> check(const Student& s) const override;
		std::unique_ptr<Requirement> clone() const override;
};

