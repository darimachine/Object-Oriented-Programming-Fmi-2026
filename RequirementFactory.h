#pragma once
#include <memory>
#include "CourseCategory.h"
#include "AdmissionRequirement.h"

class AdmissionRequirement;

class RequirementFactory {
public:
    static std::unique_ptr<AdmissionRequirement> createMinimumCredits(int credits);
    static std::unique_ptr<AdmissionRequirement> createMinimumAverageGrade(double grade);
    static std::unique_ptr<AdmissionRequirement> createMinimumCoursesFromCategory(CourseCategory category, int count);
};
