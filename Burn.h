#pragma once
#include"StatusEffect.h"
#include<iostream>

class Burn:public StatusEffect
{
public:
	Burn(int duration);

	void tick(Character& target)override;
};

