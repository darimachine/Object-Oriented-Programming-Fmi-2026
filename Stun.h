#pragma once
#include"StatusEffect.h"

class Stun:public StatusEffect
{
public:
	Stun(int duration);

	void tick(Character& target)override;
};

