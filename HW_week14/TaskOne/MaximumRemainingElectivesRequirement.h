#pragma once
#include "AdmissionRequirement.h"

class MaximumRemainingElectivesRequirement : public AdmissionRequirement 
{
    int totalRequired;
    int maxRemaining;
public:
    MaximumRemainingElectivesRequirement(int totalRequired, int maxRemaining);
    MaximumRemainingElectivesRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};

