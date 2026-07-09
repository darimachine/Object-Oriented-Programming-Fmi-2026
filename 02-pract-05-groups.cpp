#include <iostream>
#include <cstring>
#include <print>

#pragma warning (disable:4996)

namespace Constants
{
	constexpr int StudentsCount = 3;
	constexpr int MaxNameLength = 50;
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

	void print() const {
		std::println("Name: {}, Average Grade: {:.2f}", name, averageGrade);
	}
};

struct Group {
private:
	int studentsCount = 0;
	double averageGrade = 0;
	Student students[Constants::StudentsCount];

	void calculateAverageGrade() {
		if (studentsCount == 0) return;

		double sum = 0;
		for (int i = 0; i < studentsCount; i++) {
			sum += students[i].getAverageGrade();
		}

		averageGrade = sum / studentsCount;
	}

public:
	int getStudentsCount() const {
		return studentsCount;
	}

	const Student* getStudents() const {
		return students;
	}

	double getAverageGrade() const {
		return averageGrade;
	}

	void addStudent(const Student& student) {
		if (studentsCount >= Constants::StudentsCount) {
			std::println("Cannot add more students. Maximum capacity reached.");
			return;
		}

		students[studentsCount++] = student;

		if (studentsCount == Constants::StudentsCount) {
			calculateAverageGrade();
		}
	}

	void sortStudentsByGrade() {
		for (int i = 0; i < studentsCount - 1; i++) {
			for (int j = 0; j < studentsCount - i - 1; j++) {
				if (students[j].getAverageGrade() < students[j + 1].getAverageGrade()) {
					std::swap(students[j], students[j + 1]);
				}
			}
		}
	}
};

int getSchoolarshipStudentsCount(Group group, double grade) {
	int count = 0;
	const Student* students = group.getStudents();

	for (int i = 0; i < group.getStudentsCount(); i++) {
		if (students[i].getAverageGrade() >= grade) {
			count++;
		}
	}

	return count;
}

void printStudentsWithScholarship(Group group, double grade) {
	const Student* students = group.getStudents();
	std::println("Students with scholarship (grade >= {:.2f}):", grade);

	int count = getSchoolarshipStudentsCount(group, grade);
	for (int i = 0; i < count; i++) {
		students[i].print();
	}
}

int main()
{
	Student student1;
	student1.setAll("Alice", 5.5);

	Student student2;
	student2.setAll("Bob", 4.0);

	Student student3;
	student3.setAll("Charlie", 3.0);

	Group group;
	group.addStudent(student1);
	group.addStudent(student2);
	group.addStudent(student3);

	std::println("Group average grade: {:.2f}", group.getAverageGrade());
	std::println("Number of students with scholarship: {}", getSchoolarshipStudentsCount(group, 4.0));
	std::println();

	printStudentsWithScholarship(group, 4.0);
}