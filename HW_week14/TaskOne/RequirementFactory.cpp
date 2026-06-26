#include "RequirementFactory.h"
#include "InvalidRequirementConfigException.h"
#include "MinimumCreditsRequirement.h"
#include "MinimumAverageGradeRequirement.h"
#include "MinimumCoursesFromCategoryRequirement.h"
#include "MandatoryCoursesRequirement.h"
#include "MinimumElectiveCreditsRequirement.h"
#include "MaximumRemainingElectivesRequirement.h"

AdmissionRequirement* RequirementFactory::createMinimumCredits(int credits)
{
    if (credits < 0)
    {
        throw InvalidRequirementConfigException("minimum credits must be non-negative.");
    }
    return new MinimumCreditsRequirement(credits);
}

AdmissionRequirement* RequirementFactory::createMinimumAverageGrade(double grade)
{
    if (grade < 2.00 || grade > 6.00)
    {
        throw InvalidRequirementConfigException("minimum average grade must be between 2.00 and 6.00.");
    }
    return new MinimumAverageGradeRequirement(grade);
}

AdmissionRequirement* RequirementFactory::createMinimumCoursesFromCategory(CourseCategory category, int count)
{
    if (count <= 0)
    {
        throw InvalidRequirementConfigException("minimum course count must be a positive number.");
    }
    return new MinimumCoursesFromCategoryRequirement(category, count);
}

AdmissionRequirement* RequirementFactory::createMandatoryCourses(const std::vector<std::string>& courseNames)
{
    if (courseNames.empty())
    {
        throw InvalidRequirementConfigException("mandatory courses list must not be empty.");
    }
    return new MandatoryCoursesRequirement(courseNames);
}

AdmissionRequirement* RequirementFactory::createMinimumElectiveCredits(int credits)
{
    if (credits < 0)
    {
        throw InvalidRequirementConfigException("minimum elective credits must be non-negative.");
    }
    return new MinimumElectiveCreditsRequirement(credits);
}

AdmissionRequirement* RequirementFactory::createMaximumRemainingElectives(int totalRequired, int maxRemaining)
{
    if (totalRequired < 0 || maxRemaining < 0)
    {
        throw InvalidRequirementConfigException("elective course counts must be non-negative.");
    }
    return new MaximumRemainingElectivesRequirement(totalRequired, maxRemaining);
}
