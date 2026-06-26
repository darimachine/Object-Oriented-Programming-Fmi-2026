#pragma once
#include "Student.h"
#include "AdmissionRequirement.h"

class MinimumElectiveCreditsRequirement : public AdmissionRequirement 
{
    int minCredits;
public:
    explicit MinimumElectiveCreditsRequirement(int minCredits);
    MinimumElectiveCreditsRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};
