#include "Teacher.h"

Teacher::Teacher(const string& name, const string& email,
	int age, const string& degree, const string& department)
	: Person(name, email, age), degree(degree), department(department) {
}


void Teacher::addSubject(const string& subject)
{
	subjects.push_back(subject);
}

bool Teacher::teaches(const string& subject) const
{
	for (const auto& el : subjects) {
		if (el == subject) return true;
	}
	return false;
}

void Teacher::print() const
{
	Person::print();
	cout << "Степен: " << degree << "\n"
		<< "Катедра: " << department << "\n"
		<< "Предмети: ";
	for (const auto& s : subjects)
		cout << s << " ";
	cout << "\n";
}