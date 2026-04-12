#include "Student.h"

void Student::free()
{
	delete[] name;
	delete[] grades;
	name = nullptr;
	grades = nullptr;
	size = 0;
}

void Student::copyFrom(const Student& other)
{
	this->fn = other.fn;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	size = other.size;
	this->grades = new int[size];
	for (int i = 0; i < size; i++)
	{
		grades[i] = other.grades[i];
	}

}

Student::Student(const char* name, unsigned int fn, int* grades, int size)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->fn = fn;
	this->grades = new int[size];
	for (int i = 0; i < size; i++)
	{
		this->grades[i] = grades[i];
	}
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
	// TODO: insert return statement here
}

const unsigned int Student::getFn() const
{
	return fn;
}

const char* Student::getName() const
{
	return name;
}

void Student::setName(const char* name)
{
	if (!name || strlen(name) > 30 || this->name == name) {
		return;
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Student::~Student()
{
	free();
}
