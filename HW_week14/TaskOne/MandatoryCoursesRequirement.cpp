#include "MandatoryCoursesRequirement.h"
#include <iostream>

MandatoryCoursesRequirement::MandatoryCoursesRequirement(const std::vector<std::string>& courseNames) : requiredCourseNames(courseNames)
{

}

MandatoryCoursesRequirement* MandatoryCoursesRequirement::clone() const
{
	return new MandatoryCoursesRequirement(*this);
}

RequirementCheckResult MandatoryCoursesRequirement::check(const Student& student) const
{
    const auto& passed = student.getPassedCourses();
    std::string result;

    for (const auto& requirementName : requiredCourseNames)
    {
        bool found = false;

        for (const auto& course : passed)
        {
            if (course.getName() == requirementName)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            result += "Mandatory course not passed: " + requirementName;
            std::cout << std::endl;
        }
    }

    RequirementCheckResult checkResult;
    checkResult.passed = result.empty();
    checkResult.message = result;

    return checkResult;
}

