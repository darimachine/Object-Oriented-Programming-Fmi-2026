#pragma once
#include <string>
#include <print>
#include <iostream>

class Student {
public:
	std::string name;
	unsigned int id;
	int course;

	Student();
	Student(std::string name, unsigned int id, int course);
	
	void print() const;
};
