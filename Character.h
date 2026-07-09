#pragma once
#include<string>
#include<vector>
#include<memory>
#include"Weapon.h"
#include"DeadCharacterException.h"
#include"StatusEffect.h"

class Character
{
private:
	std::string name;
	int hp;
	int maxHp;
	Weapon* weapon;

protected:
	bool stunned = false;
	int damageReduction = 0;
	std::vector<std::unique_ptr<StatusEffect>> effects;

public:
	Character() = default;
	Character(const std::string& name, int hp, int maxHp,Weapon* weapon);

	virtual void attack(Character& target) = 0;
	virtual void defend(int incomingDamage) = 0;
	virtual const std::string statusLine()const = 0;
	virtual void rest() = 0;

	virtual ~Character() = default;

	bool isDead()const;
	void takeDamage(int amount);

	const std::string& getName()const;
	int getHp()const;
	Weapon* getWeapon()const;
	int getMaxHp()const;

	void setHp(int hp);

	void setStunned(bool value);
	bool isStunned()const;
	void addDamageReduction(int amount);
	int consumeDamageReduction();

	std::vector<std::unique_ptr<StatusEffect>>& getEffects();
};

