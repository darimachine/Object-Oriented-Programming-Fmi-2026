#pragma once
#include "AdmissionRequirement.h"
class RequirementFactory
{
public:
    static AdmissionRequirement* createMinimumCredits(int credits);
    static AdmissionRequirement* createMinimumAverageGrade(double grade);
    static AdmissionRequirement* createMinimumCoursesFromCategory(CourseCategory category, int count);
    static AdmissionRequirement* createMandatoryCourses(const std::vector<std::string>& courseNames);
    static AdmissionRequirement* createMinimumElectiveCredits(int credits);
    static AdmissionRequirement* createMaximumRemainingElectives(int totalRequired, int maxRemaining);
};

