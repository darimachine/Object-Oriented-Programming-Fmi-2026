#pragma once
#include"Player.h"
#include<string>

class LoggedPlayer:public Player
{
private:
	static constexpr size_t MAX_LEN_PASSWORD = 8;
	std::string password;

public:
	LoggedPlayer();
	LoggedPlayer(const std::string& password);
};

