#include "Course.h"
#include "Student.h"

Course::Course(const std::string& name, int credits, CourseCategory category, bool mandatory) 
	: name(name), credits(credits), category(category), mandatory(mandatory) 
{ 

}

const std::string& Course::getName() const
{
	return name;
}

int Course::getCredits() const
{
	return credits;
}

CourseCategory Course::getCategory() const
{
	return category;
}

bool Course::isMandatory() const
{
	return mandatory;
}