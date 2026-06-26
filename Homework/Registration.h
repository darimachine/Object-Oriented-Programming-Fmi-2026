#pragma once
#include <iostream>
#include <compare>
#include <cmath>
class Registration
{
	char* number;
public:
	Registration(char* _number);
	Registration(const Registration& other);
	void copyFrom(const Registration& other);
	bool check() const;
	void print();
	void free();
	bool operator==(const Registration& other);
	std::strong_ordering operator<=>(const Registration& other);
	void free();
	~Registration();


};

