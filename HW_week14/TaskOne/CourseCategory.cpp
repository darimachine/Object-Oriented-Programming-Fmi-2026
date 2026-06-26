#include "CourseCategory.h"

std::string categoryToString(CourseCategory category)
{
    switch (category)
    {
    case CourseCategory::Programming:
        return "Programming";
    case CourseCategory::Mathematics:
        return "Mathematics";
    case CourseCategory::AppliedMathematics:
        return "Applied Mathematics";
    case CourseCategory::Other:
        return "Other";
    }
    return "Unknown";
}
