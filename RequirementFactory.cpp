#include "RequirementFactory.h"
#include "AdmissionRequirement.h"

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumCredits(int credits)
{
    return std::make_unique<MinimumCreditsRequirement>(credits);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumAverageGrade(double grade)
{
    return std::make_unique<MinimumAverageGradeRequirement>(grade);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumCoursesFromCategory(CourseCategory category, int count)
{
    return std::make_unique<MinimumCoursesFromCategoryRequirement>(category, count);
}
