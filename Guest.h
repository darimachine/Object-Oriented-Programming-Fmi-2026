#pragma once
#include"Player.h"

class Guest:public Player
{
private:
	Time timeForPlaying;

public:
	Guest();
	Guest(const Time& timeForPlaying);

	bool levelUp()override;
};

