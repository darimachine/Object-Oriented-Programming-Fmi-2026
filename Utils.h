#pragma once
#include<string>

enum class Priority
{
	NORMAL = 1,
	EXPRESS,
	URGENT,
	OTHER
};

class Utils
{
public:
	static const std::string convertToString(Priority p);
};