#include "MagicCard.h"
#include <cstring>
#include <print>

MagicCard::MagicCard()
{
	name[0] = '\0';
	effect[0] = '\0';
	type = Type::other;
}

MagicCard::MagicCard(const char*name, const char*effect, Type type)
{
	if (!name) {
		this->name[0] = '\0';
	}
	else {
		strcpy_s(this->name, MAX_NAME, name);
	}
	if (!effect) {
		this->effect[0] = '\0';
		
	}
	else {

		strcpy_s(this->effect, MAX_EFFECT, effect);
	}

	this->type = type;
}

void MagicCard::describeCard() const
{
	std::println("Magic cards have a name, effect and a type - spell, equip or trap.");
}

const char* MagicCard::TypeToString(Type type)const
{
	switch (type) {
	case Type::spell: return "spell";
	case Type::equip: return "equip";
	case Type::trap: return "trap";
	default: return "other";
	}
}

Type MagicCard::StringToType(const char* typeStr)
{
	if (!typeStr)
		return Type::other;

	if (strcmp(typeStr, "spell") == 0)
		return Type::spell;
	if (strcmp(typeStr, "equip") == 0)
		return Type::equip;
	if (strcmp(typeStr, "trap") == 0)
		return Type::trap;

	return Type::other;
}

void MagicCard::print() const
{
	const char* typeStr = TypeToString(type);
	std::println("{} is a {} with the following effect - \"{}.\"", name,typeStr, effect);
}
