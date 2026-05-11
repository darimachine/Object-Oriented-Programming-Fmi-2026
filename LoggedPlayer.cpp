#include "LoggedPlayer.h"
#include<stdexcept>

LoggedPlayer::LoggedPlayer() :Player(), password("") {}

LoggedPlayer::LoggedPlayer(const std::string& password) :
	Player()
{
	if (password.size() > MAX_LEN_PASSWORD)
	{
		throw std::invalid_argument("Password length must not exceed 8 characters.");
	}
	this->password = password;
}
