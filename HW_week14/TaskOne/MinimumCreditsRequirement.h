#pragma once
#include "AdmissionRequirement.h"
class MinimumCreditsRequirement : public AdmissionRequirement
{
    int minCredits;
public:
    explicit MinimumCreditsRequirement(int minCredits);
    MinimumCreditsRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};

