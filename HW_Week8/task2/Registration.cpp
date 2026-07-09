#define _CRT_SECURE_NO_WARNINGS
#include "Registration.h"

bool isMyAlpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isMyDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool Registration::checkLetters(const char* str, int start, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (!isMyAlpha(str[start + i]))
		{
			return false;
		}
	}
	return true;
}

bool Registration::checkDigits(const char* str, int start, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (!isMyDigit(str[start + i]))
		{
			return false;
		}
	}
	return true;
}

Registration::Registration(const char* str)
{
	if (!str || !validate(str))
	{
		reg[0] = '\0';
		return;
	}
	if (strlen(str) >= Registration::MAX_REG_NUMBER)
	{
		reg[0] = '\0';
		return;
	}

	strcpy(reg, str);
}

const char* Registration::toString() const
{
	return reg;
}

bool Registration::isValid() const
{
	return reg[0] != '\0';
}

bool Registration::operator==(const Registration& other) const
{
	return (strcmp(reg, other.reg) == 0);
}

bool Registration::operator!=(const Registration& other) const
{
	return !(*this == other);
}

bool Registration::operator<(const Registration& other) const
{
	return (strcmp(reg, other.reg) < 0);
}

bool Registration::operator>(const Registration& other) const
{
	return (other < *this);
}

void Registration::getCity(char* out) const
{ 
	int i;
	for (i = 0; reg[i] && isMyAlpha(reg[i]); i++)
	{
		out[i] = reg[i];
	}
	out[i] = '\0';
}

bool Registration::validate(const char* str)
{
	if (!str)
	{
		return false;
	}

	int len = strlen(str);
	if (len != 7 && len != 8)
	{
		return false;
	}

	int prefix = (len == 7) ? 1 : 2;

	if (!checkLetters(str, 0, prefix))
	{
		return false;
	}

	if (!checkDigits(str, prefix, 4))
	{
		return false;
	}

	if (!checkLetters(str, prefix + 4, len - (prefix + 4)))
	{
		return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& os, const Registration& registration)
{
	return os << registration.reg;
}
