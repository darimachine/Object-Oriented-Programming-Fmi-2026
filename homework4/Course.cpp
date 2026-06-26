#include "Course.h"

Course::Course(std::string n, int c, CourseCategory cc, bool m) 
	: name(std::move(n)), credits(c), category(cc), mandatory(m) {}

const std::string& Course::getName() const {
	return name;
}

int Course::getCredits() const {
	return credits;
}

CourseCategory Course::getCourseCategory() const {
	return category;
}

bool Course::isMandatory() const {
	return mandatory;
}
