#include <iostream>
#include <ostream>
#include <fstream>
#include <print>
#include <cstring>

#pragma warning (disable: 4996)

namespace Constants
{
	constexpr int MaxNameLength = 50;
	constexpr int StudentsCount = 3;
}

struct Student {
private:
	char name[Constants::MaxNameLength];
	double averageGrade;

public:
	const char* getName() const {
		return name;
	}

	void setName(const char* name) {
		if (!name) return;
		strcpy(this->name, name);
	}

	double getAverageGrade() const {
		return averageGrade;
	}

	void setAverageGrade(double averageGrade) {
		if (averageGrade < 2.0 || averageGrade > 6.0) return;
		this->averageGrade = averageGrade;
	}

	void setAll(const char* name, double averageGrade) {
		setName(name);
		setAverageGrade(averageGrade);
	}

	void saveToFile(std::ostream& os) const {
		std::println(os, "{},{}", name, averageGrade);
	}
};

void saveStudentArrayToFile(const Student(&students)[Constants::StudentsCount], const char* fileName) {
	std::ofstream os(fileName);
	if (!os.is_open()) return;

	for (int i = 0; i < Constants::StudentsCount; i++)
	{
		students[i].saveToFile(os);
	}
}

void loadStudentArrayFromFile(Student (&students)[Constants::StudentsCount], const char* fileName) {
	std::ifstream is(fileName);
	if (!is.is_open()) return;

	for (int i = 0; i < Constants::StudentsCount; i++)
	{
		char name[Constants::MaxNameLength];
		is.getline(name, Constants::MaxNameLength, ',');

		double grade;
		is >> grade;

		students[i].setAll(name, grade);
		is.ignore();
	}
}

int main() {

	Student students[Constants::StudentsCount];

	loadStudentArrayFromFile(students, "input.txt");
	saveStudentArrayToFile(students, "output.txt");
}