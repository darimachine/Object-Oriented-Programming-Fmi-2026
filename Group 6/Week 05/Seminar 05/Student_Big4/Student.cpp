#include "Student.h"

void Student::free()
{
	delete[] name;
	delete[] grades;
	name = nullptr;
	grades = nullptr;
}
//char* name = nullptr;
//unsigned int fn;
//
//double* grades = nullptr;
//int gradeCount = 0;
//int gradeCapacity = 8;
//
//char quote[MAX_SIZE];
void Student::copyFrom(const Student& other)
{
	fn = other.fn;
	gradeCount = other.gradeCount;
	gradeCapacity = other.gradeCapacity;

	strcpy(quote, other.quote);

	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy(name, other.name);

	grades = new double[gradeCapacity] {};
	for (int i = 0; i < gradeCount; i++)
	{
		grades[i] = other.grades[i];
	}
}

void Student::resize(int newCap)
{
	gradeCapacity = newCap;
	double* temp = new double[newCap];
	for (int i = 0; i < gradeCount; i++)
	{
		temp[i] = grades[i];
	}
	delete[] grades;
	grades = temp;

}

Student::Student(const char* name, unsigned int fn, const char* quote)
{
	setName(name);
	setFn(fn);
	setQuote(quote);
}

Student::Student(const char* name, unsigned int fn, double* grades, int gradeCount, const char* quote)
{
	setName(name);
	setFn(fn);
	setQuote(quote);
	setGrades(grades, gradeCount);
}

Student::Student(const Student& other)
{
	copyFrom(other);
}

Student& Student::operator=(const Student& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Student::~Student()
{
	free();
}

unsigned int Student::getFn() const
{
	return fn;
}

void Student::setFn(unsigned int fn)
{
	this->fn = fn;
}

const char* Student::getName() const
{
	return name;
}

void Student::setName(const char* name)
{
	if (name == nullptr || this->name == name) {
		return;
	}
	int len = strlen(name);
	delete[] this->name;
	this->name = new char[len + 1];

	strcpy(this->name, name);
}

const char* Student::getQuote() const
{
	return quote;
}

void Student::setQuote(const char* quote)
{
	int len = strlen(name);
	if (quote == nullptr || this->quote == quote || len >MAX_SIZE) {
		return;
	}
	strcpy(this->quote, quote);
}

double* Student::getGrades() const
{
	return grades;
}

void Student::setGrades(const double* grades, int gradeCount)
{
	if (grades == nullptr || this->grades == grades || gradeCount == 0) {
		return;
	}
	delete[] this->grades;
	this->gradeCount = gradeCount;
	gradeCapacity = gradeCount;

	this->grades = new double[gradeCapacity];
	for (int i = 0; i < gradeCount; i++)
	{
		this->grades[i] = grades[i];
	}

}

int Student::getGradeCount() const
{
	return gradeCount;
}

double Student::getAverageGrade() const
{
	double sum = 0;
	for (int i = 0; i < gradeCount; i++)
	{
		sum += grades[i];
	}
	return sum/gradeCount;
}

void Student::addGrade(double grade)
{
	if (grade < 2.00 || grade>6.00) {
		return;
	}
	if (gradeCount == gradeCapacity) {
		resize(gradeCapacity * 2);
	}
	grades[gradeCount++] = grade;
}

void Student::removeGradeAt(int index)
{
	if(index <0 || index >= gradeCount) {
		return;
	}
	grades[index] = grades[gradeCount - 1];
	gradeCount--;
}
