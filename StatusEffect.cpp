#include "StatusEffect.h"

StatusEffect::StatusEffect(int duration):duration(duration){}

bool StatusEffect::isExpired()const
{
	return duration <= 0;
}