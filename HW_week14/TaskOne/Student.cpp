#include "Student.h"

Student::Student(const std::string& facultyNumber, const std::string& name, int totalCredits, double averageGrade) 
	: facultyNumber(facultyNumber), name(name), totalCredits(totalCredits), averageGrade(averageGrade)
{

}

void Student::addCourse(const Course& course)
{
	passedCourses.push_back(course);
}

const std::string& Student::getFacultyNumber() const
{
	return facultyNumber;
}

const std::string& Student::getName() const 
{
	return name;
}

const std::vector<Course>& Student::getPassedCourses() const
{
	return passedCourses;
}

int Student::getTotalCredits() const
{
	return totalCredits;
}

double Student::getAverageGrade() const
{
	return averageGrade;
}
