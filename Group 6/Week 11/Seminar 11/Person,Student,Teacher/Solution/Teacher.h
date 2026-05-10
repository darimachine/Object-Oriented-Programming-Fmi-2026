#pragma once
#include "Person.h"
class Teacher : public Person
{
	string department;
	string degree;
	vector<string> subjects;

public:
	Teacher(const string& name, const string& email, int age, const string& department, const string& degree);

	void addSubject(const string& subject);
	bool teaches(const string& subject) const;
	void print() const;
};

