#include "Character.h"
#include "Stun.h"

Stun::Stun(int duration):StatusEffect(duration){}

void Stun::tick(Character& target)
{
	target.setStunned(true);
	duration--;
}