#pragma once
#include <string>

enum class CourseCategory {
	Programming, Mathematics, AppliedMathematics, Last
};

class Course {
	std::string name;
	int credits;
	CourseCategory category;
	bool mandatory;

public:
	explicit Course(std::string, int, CourseCategory, bool);
	const std::string& getName() const;
	int getCredits() const;
	CourseCategory getCourseCategory() const;
	bool isMandatory() const;
};

