#include "Soldier.h"
#include <random>

Soldier::Soldier(int hp, Rank rank, int LOVE, int ammoLeft) : hp(hp), rank(rank), LOVE(LOVE), ammoLeft(ammoLeft) {}

void Soldier::getShot()
{
	hp -= 40;

	if (hp < 0) hp = 0;
}

void Soldier::shootAt(Soldier& enemy)
{
	if (ammoLeft <= 0) return;

	ammoLeft--;

	int chance = 0;
	switch (rank) {
	case Rank::Private:
		chance = 0.6 * 100;
		break;
	case Rank::Corporal:
		chance = 0.7 * 100;
		break;
	case Rank::Sergeant:
		chance = 0.8 * 100;
		break;
	case Rank::Major:
		chance = 0.9 * 100;
		break;
	}

	if (std::rand() % 100 >= chance) return;

	LOVE++;
	enemy.getShot();
}

int Soldier::getHP() const
{
	return hp;
}

Rank Soldier::getRank() const
{
	return rank;
}

int Soldier::getLOVE() const
{
	return LOVE;
}

void Soldier::promote(Soldier& soldier)
{
	if (rank <= soldier.getRank()) return;
	
	int loveNeeded = 0;
	switch (soldier.getRank())
	{
	case Rank::Private:
		loveNeeded = 10;
		break;
	case Rank::Corporal:
		loveNeeded = 20;
		break;
	case Rank::Sergeant:
		loveNeeded = 30;
		break;
	case Rank::Major:
		loveNeeded = 40;
		break;
	}

	if (soldier.LOVE < loveNeeded) return;

	soldier.getPromoted();
}

void Soldier::getPromoted()
{
	switch (rank)
	{
	case Rank::Private:
		rank = Rank::Corporal;
		break;
	case Rank::Corporal:
		rank = Rank::Sergeant;
		break;
	case Rank::Sergeant:
		rank = Rank::Major;
		break;
	}
}
