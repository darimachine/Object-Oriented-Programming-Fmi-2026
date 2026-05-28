#include "Course.h"

std::string to_string(CourseCategory cat)
{
    switch (cat) {
    case CourseCategory::Programming: return "Programming";
    case CourseCategory::Mathematics: return "Mathematics";
    case CourseCategory::AppliedMathematics: return "Applied Mathematics";
    default: return "Other";
    }
}
