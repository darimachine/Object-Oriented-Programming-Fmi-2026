#include "GenreConverter.h"
#include<cstring>

const char* GenreConverter::convertToString(const Genre& genre)
{
	switch (genre)
	{
	case Genre::CLASSICAL:return "Classical";
	case Genre::POP:return "Pop";
	case Genre::POPFOLK: return "Pop folk";
	case Genre::ROCK: return "Rock";
	default:return "Other";
	}
}

Genre GenreConverter::convertToGenre(const char* genre)
{
	if (strcmp(genre, "Classical") == 0)
	{
		return Genre::CLASSICAL;
	}
	else if (strcmp(genre, "Pop") == 0)
	{
		return Genre::POP;
	}
	else if (strcmp(genre, "Pop folk") == 0)
	{
		return Genre::POPFOLK;
	}
	else if (strcmp(genre, "Rock") == 0)
	{
		return Genre::ROCK;
	}
	else
	{
		return Genre::OTHER;
	}
}