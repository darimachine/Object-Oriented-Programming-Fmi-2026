#define _CRT_SECURE_NO_WARNINGS
#include "MagicCard.h"


MagicCard::MagicCard():type(Type::SPELL)
{
	strcpy(name, " ");
	strcpy(effect, " ");
}

MagicCard::MagicCard(const char* name, const char* effect, const char* type)
{
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = TypeConverter::convertToType(type);
}

void MagicCard::describeType()
{
	std::println("Magic cards have a name, effect and a type - spell, equip or trap.");
}

void MagicCard::printInfo()const
{
	std::println("{} is a {} with the following effect - {}.",name,
		TypeConverter::converToString(type),effect);
}