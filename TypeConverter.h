#pragma once
#include"Type.h"

class TypeConverter
{
public:

	static const char* converToString(Type type);
	static const Type convertToType(const char* type);
};

