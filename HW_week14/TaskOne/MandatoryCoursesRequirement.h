#pragma once
#include <vector>
#include "AdmissionRequirement.h"

class MandatoryCoursesRequirement : public AdmissionRequirement 
{
    std::vector<std::string> requiredCourseNames;
public:
    explicit MandatoryCoursesRequirement(const std::vector<std::string>& courseNames);
    MandatoryCoursesRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};