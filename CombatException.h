#pragma once
#include<stdexcept>
#include<string>

class CombatException :public std::exception
{
private:
	std::string message;

public:
	explicit CombatException(const std::string& message);

	const char* what()const noexcept override;
};

