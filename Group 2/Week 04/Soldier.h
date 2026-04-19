#pragma once

enum class Rank {
	Private,
	Corporal,
	Sergeant,
	Major
};

class Soldier
{
private:
	int hp = 100;
	Rank rank = Rank::Private;
	int LOVE = 0;
	int ammoLeft = 100;
public:
	Soldier() = default;
	Soldier(int hp, Rank rank, int LOVE, int ammoLeft);
	void getShot();
	void shootAt(Soldier& enemy);
	int getHP() const;
	Rank getRank() const;
	int getLOVE() const;
	void promote(Soldier& enemy);
	void getPromoted();
};
