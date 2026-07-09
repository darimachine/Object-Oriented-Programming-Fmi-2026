#pragma once
#include"Genre.h"

class GenreConverter
{
public:
	static const char* convertToString(const Genre& g);
	static Genre convertToGenre(const char* genre);
};

