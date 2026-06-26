#pragma once
#include <string>
#include "CourseCategory.h"
class Course
{
private:
    std::string name;
    int credits;
    CourseCategory category;
    bool mandatory;
public:
    Course(const std::string& name, int credits, CourseCategory category, bool mandatory);
    const std::string& getName() const;
    int getCredits() const;
    CourseCategory getCategory() const;
    bool isMandatory() const;
};

