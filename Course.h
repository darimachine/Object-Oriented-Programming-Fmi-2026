#pragma once
#include "CourseCategory.h"
#include <string>

struct Course {
    std::string name;
    int credits;
    CourseCategory category;
    bool isMandatory;
};

std::string to_string(CourseCategory cat);
