#pragma once
#include"Player.h"
#include<string>

class PremiumPlayer:public Player
{
private:
	static constexpr int POINTS_FOR_STAR = 256;
	std::string name;

public:
	PremiumPlayer();
	PremiumPlayer(const std::string& name);

	bool levelUp()override;
};

