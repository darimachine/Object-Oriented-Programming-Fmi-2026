#pragma once
#include <iostream>
class Registration
{
	char city[3] = {};
	char digits[5] = {};
	char symbols[3] = {};
	mutable char number[9] = {};
public:
	Registration() = delete;
	Registration(const char* registrationNumbre);
	friend std::ostream& operator<<(std::ostream& os, const Registration& r);
	const char* getNumber() const;
	auto operator<=>(const Registration& other) const;
	bool operator==(const Registration& other)const;
};
std::ostream& operator<<(std::ostream& os, const Registration& r);
