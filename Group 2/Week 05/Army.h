#pragma once
#include "Soldier.h"

class Army
{
private:
	int size = 0;
	int capacity = 10;
	Soldier* army = new Soldier[capacity];

	void resize(int newSize);
public:
	Army() = default;
	Army(int size);
	Army(int size, const Soldier& example);
	Army(const Army& other);
	~Army();
	Army& operator=(const Army& other);
	int getSize() const;
	Soldier& getSoldier(int soldierId);
	const Soldier& getSoldier(int soldierId) const;
	void addSoldier(const Soldier& soldier);
	void removeSoldier(int soldierId);
};
