#pragma once
#include"Group.h"

class Team:public Group
{
private:
	std::vector< std::pair < std::string, std::string>> relations;

public:
	Team() = default;
	
	bool operator()(const Person& first, const Person& second);
	size_t countManagers()const;
};

std::strong_ordering operator<=>(const Team& lhs, const Team& rhs);
bool operator==(const Team& lhs, const Team& rhs);