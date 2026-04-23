#pragma once

enum class Type {
	spell, equip, trap, other
};

class MagicCard
{
private:
	static constexpr unsigned int MAX_NAME = 25;
	static constexpr unsigned int MAX_EFFECT = 100;
	char name[MAX_NAME];
	char effect[MAX_EFFECT];
	Type type;

public:
	MagicCard();
	MagicCard(const char*, const char*, Type);

	void describeCard()const;
	const char* TypeToString(Type)const;
	Type StringToType(const char*);
	void print()const;
};

