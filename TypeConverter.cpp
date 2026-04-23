#include "TypeConverter.h"
#include<cstring>

const char* TypeConverter::converToString(Type type)
{
	switch (type)
	{
	case Type::SPELL:return "spell";
	case Type::EQUIP: return "equip";
	case Type::TRAP:return "trap";
	default:return "none";
	}
}

const Type TypeConverter::convertToType(const char* type)
{
	if (strcmp(type, "spell") == 0)
	{
		return Type::SPELL;
	}
	else if (strcmp(type, "equip") == 0)
	{
		return Type::EQUIP;
	}
	else if (strcmp(type, "trap") == 0)
	{
		return Type::TRAP;
	}
	else
	{
		return Type::NONE;
	}
}