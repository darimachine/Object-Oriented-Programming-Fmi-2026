#include "Student.h"
#include <optional>
#include <numeric>

Student::Student(const string& name, const string& email, int age, const string& fn, const string& specialty) : Person(name,email,age),fn(fn),specialty(specialty)
{
}

void Student::addExam(const string& subject, double grade)
{
	if (grade < 2.0 || grade> 6.0) return;
	//Option 1
	/*auto c = std::make_pair(subject, grade);
	exams.push_back(c);*/
	// Option 2
	//exams.push_back({ subject,grade });
	exams.emplace_back(subject, grade);
}

double Student::getAverage() const
{
	if (exams.empty()) {
		return 0;
	}
	double sum = 0;
	for (const auto& [subject, grade] : exams) {
		sum += grade;
	}
	return sum/exams.size();
}

bool Student::hasPassed(const string& subject) const
{
	for (const auto& [sub, grade] : exams) {
		if (sub == subject) {
			return grade > 3.0;
		}
	}
	return false;
}

void Student::print() const
{
	Person::print();
	cout << "ФН: " << fn << "\n"
		<< "Специалност: " << specialty << "\n"
		<< "Изпити:\n";
	for (const auto& [subject, grade] : exams)
		cout << "  " << subject << ": " << grade << "\n";
	cout << "Среден успех: " << getAverage() << "\n";
}