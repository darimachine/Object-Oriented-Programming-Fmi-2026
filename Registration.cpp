#define _CRT_SECURE_NO_WARNINGS
#include "Registration.h"
#include<cstring>

Registration::Registration(const char* plate)
{
	if (!isValid(plate))
	{
		return;
	}

	strcpy(this->plate, plate);
	setCode(plate);
}

bool Registration::isValid(const char* plate)
{
	if (plate == nullptr)
	{
		return false;
	}

	int len = strlen(plate);
	if (len != 7 && len != 8)
	{
		return false;
	}

	size_t index = 0;

	if (!UtilsVehicles::isUpper(plate[index]))
	{
		return false;
	}

	index++;

	if (UtilsVehicles::isUpper(plate[index]))
	{
		index++;
	}

	for (size_t i = 0;i < 4;i++)
	{
		if (!UtilsVehicles::isDigit(plate[index]))
		{
			return false;
		}
		index++;
	}

	if (!UtilsVehicles::isUpper(plate[index]) || !UtilsVehicles::isUpper(plate[index + 1]))
	{
		return false;
	}

	index += 2;

	return plate[index] == '\0';
}

void Registration::setCode(const char* plate)
{
	if (strlen(plate) == 7)
	{
		strncpy(code, plate, 1);
		code[1] = '\0';
	}
	else if (strlen(plate) == 8)
	{
		strncpy(code, plate, 2);
		code[2] = '\0';
	}
}

std::ostream& operator<<(std::ostream& os, const Registration& registration)
{
	os << registration.plate;
	return os;
}

std::strong_ordering operator<=>(const Registration& lhs, const Registration& rhs)
{
	return lhs.getPlate() <=> rhs.getPlate();
}

const char* Registration::getPlate()const
{
	return plate;
}

const char* Registration::getCode()const
{
	return code;
}

bool operator==(const Registration& lhs, const Registration& rhs)
{
	return strcmp(lhs.getPlate(), rhs.getPlate()) == 0;
}