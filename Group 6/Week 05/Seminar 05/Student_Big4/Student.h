#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
class Student {

	static constexpr int MAX_SIZE = 31;

	char* name= nullptr;
	unsigned int fn;

	double* grades = nullptr;
	int gradeCount = 0;
	int gradeCapacity = 8;

	char quote[MAX_SIZE];

	void free();
	void copyFrom(const Student& other);

	void resize(int newCap);
public:

	//no default constructor on purpose!!!
	Student(const char*, unsigned int fn, const char* quote);
	Student(const char* name, unsigned int fn, double* grades, int gradeCount, const char* quote);

	Student(const Student& other);
	Student& operator=(const Student&);
	~Student();

	unsigned int getFn() const;
	void setFn(unsigned int Fn);

	const char* getName() const;
	void setName(const char*);

	const char* getQuote() const;
	void setQuote(const char*);

	double* getGrades() const;
	void setGrades(const double* grades, int gradeCount);

	int getGradeCount() const;

	double getAverageGrade() const;

	void addGrade(double grade);

	void removeGradeAt(int index);

};
