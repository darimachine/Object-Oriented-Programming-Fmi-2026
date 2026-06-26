#include "RequirementFactory.h"
#include "Exceptions.h"

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumCredits(int minCredits) {
    if (minCredits <= 0)
        throw InvalidRequirementConfigException("Minimum credits cannot be negative or zero.");
    return std::make_unique<MinimumCreditsRequirement>(minCredits);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createRequiredCoursesByName(std::vector<std::string> requiredCourses) {
    if (requiredCourses.empty())
        throw InvalidRequirementConfigException("Required courses list cannot be empty.");
    return std::make_unique<RequiredCoursesByNameRequirement>(std::move(requiredCourses));
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumCoursesFromCategory(int minCount, CourseCategory category) {
    if (minCount <= 0)
        throw InvalidRequirementConfigException("Minimum courses from category cannot be negative or zero.");
    if (category >= CourseCategory::Last)
        throw InvalidRequirementConfigException("Invalid course category.");
    return std::make_unique<MinimumCoursesFromCategoryRequirement>(minCount, category);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumElectiveCredits(int minCredits) {
    if (minCredits <= 0)
        throw InvalidRequirementConfigException("Minimum credits cannot be negative or zero.");
    return std::make_unique<MinimumElectiveCreditsRequirement>(minCredits);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMaxRemainingElectiveCourses(int maxCount, int totalElectives) {
    if (totalElectives < 0)
        throw InvalidRequirementConfigException("Total elective courses cannot be negative.");
    if (maxCount < 0)
        throw InvalidRequirementConfigException("Max remaining elective courses cannot be negative.");
    if (maxCount > totalElectives)
        throw InvalidRequirementConfigException("Max remaining cannot exceed total elective courses.");
    return std::make_unique<MaxRemainingElectiveCoursesRequirement>(maxCount, totalElectives);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createMinimumAverageGrade(double minGrade) {
    if (minGrade < 2 || minGrade > 6)
        throw InvalidRequirementConfigException("Minimum average grade must be in the range [2.00,6.00].");
    return std::make_unique<MinimumAverageGradeRequirement>(minGrade);
}

std::unique_ptr<AdmissionRequirement> RequirementFactory::createNoFailedMandatoryCourses(std::vector<Course> allMandatories) {
    if (allMandatories.empty())
        throw InvalidRequirementConfigException("Mandatory courses list cannot be empty.");
    return std::make_unique<NoFailedMandatoryCoursesRequirement>(std::move(allMandatories));
}
