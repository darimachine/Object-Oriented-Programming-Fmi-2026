#pragma once
#include <string>

constexpr int MIN_COURSE = 1;
constexpr int MAX_COURSE = 4;
class Student
{
	private:
		std::string name;
		unsigned personalID;
		static unsigned ID;
		int course;

		void setCourse(int inpCourse);

	public:
		Student(const std::string& inpName, int inpCourse);
		const unsigned getPersonalID() const;
		void displayStudentInfo() const;
		const std::string& getName() const;
		const int getCourse() const;
		Student();
		
};

