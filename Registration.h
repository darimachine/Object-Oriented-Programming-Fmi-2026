#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <compare>
class Registration {
	static const unsigned SIZE = 9;
	char plate[SIZE];
	
	bool isValid(const char* str);
public:
	Registration() = delete;
	Registration(const char* str);

	friend std::ostream& operator<<(std::ostream& os, const Registration& r);
	const char* getPlate() const;
};
bool operator==(const Registration& lhs, const Registration& rhs);
bool operator!=(const Registration& lhs, const Registration& rhs);
std::strong_ordering operator<=>(const Registration& lhs, const Registration& rhs);