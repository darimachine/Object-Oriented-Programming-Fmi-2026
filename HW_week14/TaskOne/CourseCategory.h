#pragma once
#include <string>

enum class CourseCategory
{
    Programming,
    Mathematics,
    AppliedMathematics,
    Other
};

std::string categoryToString(CourseCategory category);
