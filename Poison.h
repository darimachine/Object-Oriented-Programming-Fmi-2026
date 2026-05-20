#pragma once
#include"StatusEffect.h"
#include<iostream>

class Poison:public StatusEffect
{
public:
	Poison(int duration);
	void tick(Character& target)override;
};

