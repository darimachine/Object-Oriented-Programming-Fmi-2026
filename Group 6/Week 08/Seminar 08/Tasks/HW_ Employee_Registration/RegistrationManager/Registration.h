#pragma once
#pragma warning (disable : 4996)
#include <cstring>
#include <iostream>


class Registration
{
private:
	static constexpr short MAX_DIGITS = 4;
	static constexpr short MAX_LETTERS = 3;
	static constexpr short MAX_LETTERS_FULL = 9;

	char cityCode[MAX_LETTERS];
	char full[MAX_LETTERS_FULL];

public:
	Registration() = delete;
	Registration(const char* reg);

	char* getFull() { return full; }
	char* getCityCode() { return cityCode; }

	std::strong_ordering operator<=>(const Registration& other) const;
	bool operator==(const Registration& other) const;
	explicit operator bool() const;

	friend std::ostream& operator<<(std::ostream& os, const Registration& reg);
};

