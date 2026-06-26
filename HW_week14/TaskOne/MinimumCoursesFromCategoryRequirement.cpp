#include "MinimumCoursesFromCategoryRequirement.h"
#include "Utils.h"

MinimumCoursesFromCategoryRequirement::MinimumCoursesFromCategoryRequirement(CourseCategory category, int minCount) : category(category), minCount(minCount)
{

}

MinimumCoursesFromCategoryRequirement* MinimumCoursesFromCategoryRequirement::clone() const
{
	return new MinimumCoursesFromCategoryRequirement(*this);
}

RequirementCheckResult MinimumCoursesFromCategoryRequirement::check(const Student& student) const
{
    int count = 0;
    for (const auto& c : student.getPassedCourses())
    {
        if (c.getCategory() == category)
        {
            count++;
        }
    }
    RequirementCheckResult result;
    if (count >= minCount)
    {
        result.passed = true;
        result.message = "";
        return result;
    }
    std::string message = "Student has completed ";
    message += formatDouble(count);
    message += " ";
    message += categoryToString(category);
    message += " courses, but at least ";
    message += formatDouble(minCount);
    message += " are required.";
    result.passed = false;
    result.message = message;

    return result;
}

