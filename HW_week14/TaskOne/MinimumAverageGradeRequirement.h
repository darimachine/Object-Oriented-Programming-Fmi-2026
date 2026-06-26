#pragma once
#include "AdmissionRequirement.h"
class MinimumAverageGradeRequirement : public AdmissionRequirement 
{
    double minGrade;
public:
    explicit MinimumAverageGradeRequirement(double minGrade);
    MinimumAverageGradeRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};

