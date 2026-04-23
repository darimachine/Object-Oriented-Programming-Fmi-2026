#pragma once
#include"UtilsVehicles.h"
#include<fstream>

class Registration
{
private:
	static constexpr size_t PLATE_SIZE = 9;
	static constexpr size_t CODE_SIZE = 3;

	char plate[PLATE_SIZE]{};
	char code[CODE_SIZE]{};

	bool isValid(const char* plate);

public:
	Registration() = delete;
	Registration(const char* plate);

	void setCode(const char* plate);

	const char* getPlate()const;
	const char* getCode()const;

	friend std::ostream& operator<<(std::ostream& os, const Registration& registration);
};

std::strong_ordering operator<=>(const Registration& lhs, const Registration& rhs);
bool operator==(const Registration& lhs, const Registration& rhs);