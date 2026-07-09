#pragma once

#include <iostream>
#include "Util.h"
class Registration
{
	const static int MAX_REG_LEN = 10;

private:
	char number[MAX_REG_LEN]="";
	bool validateNumber(const char* _number) const;
public:
	Registration() = delete;
	Registration(const char* _number);

	friend std::ostream& operator<<(std::ostream& os, Registration& s);

	char* getNumber();
	bool operator==(Registration& other);
	std::strong_ordering operator<=>(Registration& other);
};

