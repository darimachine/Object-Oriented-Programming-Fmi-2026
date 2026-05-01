#pragma once

#include "Person.h"

class Student : public Person {
	
	string fn;
	string specialty;
	vector<pair<string, double>> exams;

public:
	Student(const string& name, const string& email, int age, const string& fn, const string& specialty);

	void addExam(const string& subject, double grade);

	double getAverage() const;

	bool hasPassed(const string& subject) const;

	void print() const;

};