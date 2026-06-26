#pragma once
#include "CourseCategory.h"
#include "AdmissionRequirement.h"

class MinimumCoursesFromCategoryRequirement : public AdmissionRequirement 
{
    CourseCategory category;
    int minCount;
public:
    MinimumCoursesFromCategoryRequirement(CourseCategory category, int minCount);
    MinimumCoursesFromCategoryRequirement* clone() const override;
    RequirementCheckResult check(const Student& student) const override;
};