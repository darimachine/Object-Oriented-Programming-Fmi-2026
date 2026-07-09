#include "Utils.h"

bool Utils::hasLetters(const std::string& s)
{
	for (size_t i = 0;i < s.size(); i++)
	{
		if (upperCase(s[i]) || lowerCase(s[i]))
		{
			return true;
		}
	}
	return false;
}

bool Utils::upperCase(char s)
{
	return s >= 'A' && s <= 'Z';
}

bool Utils::lowerCase(char s)
{
	return s >= 'a' && s <= 'z';
}