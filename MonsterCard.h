#pragma once
class MonsterCard
{
private:
	char* name = nullptr;
	unsigned int defence = 0;
	unsigned int attack = 0;

	void copyFrom(const MonsterCard&);
	void free();

public:
	MonsterCard();
	MonsterCard(const char*, unsigned int, unsigned int);
	MonsterCard(const MonsterCard&);
	MonsterCard& operator= (const MonsterCard&);
	~MonsterCard();

	void describeCard() const;
	void print() const;
};

