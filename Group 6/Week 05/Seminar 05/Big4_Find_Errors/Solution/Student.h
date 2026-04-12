#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class Student {

	unsigned int fn;
	char* name;
	int* grades = nullptr;
	int size = 0;

	void free();
	void copyFrom(const Student& other);

public:

	//no default constructor on purpose!!!
	Student(const char*, unsigned int fn, int* grades, int size);
	Student(const Student&);
	Student& operator=(const Student&);

	const unsigned int getFn() const;

	const char* getName() const;

	void setName(const char*);

	~Student();
};

