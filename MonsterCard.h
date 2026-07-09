#pragma once
class MonsterCard
{
private:
	static constexpr int DEFAULT_SIZE_NAME = 0;
	char* name;
	unsigned int attackPoints;
	unsigned int defensePoints;

	void copyFrom(const MonsterCard& other);
	void free();

public:

	MonsterCard();

	MonsterCard(const char* name, unsigned int attack, unsigned int defense);

	~MonsterCard();

	MonsterCard(const MonsterCard& other);

	MonsterCard& operator=(const MonsterCard& other);

	static void describeType();

	void printInfo()const;
};

