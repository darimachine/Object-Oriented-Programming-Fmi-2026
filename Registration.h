#pragma once
#include <iostream>

class Registration
{
private:
	static constexpr size_t SIZE = 9;
	static constexpr size_t CODE_SIZE = 3;

	char code[CODE_SIZE];

	char plate[SIZE];

	bool isValid(const char* plate);

public:
	Registration(const char* plate);

	const char* getPlate()const;
	const char* getCode()const;

	friend std::ostream& operator<<(std::ostream&, const Registration&);
};

bool operator==(const Registration&, const Registration&);
std::strong_ordering operator<=>(const Registration&, const Registration&);

