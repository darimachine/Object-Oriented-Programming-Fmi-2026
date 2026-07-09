#include "TypeConverter.h"
#include <cstring>

const char* TypeConverter::TypeToString(Genre g)
{
    switch (g)
    {
    case Genre::ROCK: return ROCK_STR;
    case Genre::POP: return POP_STR;
    case Genre::JAZZ: return JAZZ_STR;
    case Genre::HIPHOP: return HIPHOP_STR;
    case Genre::ELECTRONIC: return ELECTRONIC_STR;
    default: return OTHER_STR;
    }
}

Genre TypeConverter::StringToType(const char* str)
{
    if (strcmp(str, ROCK_STR) == 0) return Genre::ROCK;
    if (strcmp(str, POP_STR) == 0) return Genre::POP;
    if (strcmp(str, JAZZ_STR) == 0) return Genre::JAZZ;
    if (strcmp(str, HIPHOP_STR) == 0) return Genre::HIPHOP;
    if (strcmp(str, ELECTRONIC_STR) == 0) return Genre::ELECTRONIC;

    return Genre::OTHER;
}
