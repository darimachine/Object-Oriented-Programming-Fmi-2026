#pragma once
#include <string>

class Character;

class StatusEffect
{
protected:
	int duration;

public:
	StatusEffect(int duration);

	virtual void tick(Character& target) = 0;
	virtual bool isExpired()const;

	virtual ~StatusEffect() = default;
};
