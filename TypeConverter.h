#pragma once
#include"Song.h"

class TypeConverter
{
private:
    static constexpr const char* ROCK_STR = "rock";
    static constexpr const char* POP_STR = "pop";
    static constexpr const char* JAZZ_STR = "jazz";
    static constexpr const char* HIPHOP_STR = "hiphop";
    static constexpr const char* ELECTRONIC_STR = "electronic";
    static constexpr const char* OTHER_STR = "other";
public:
    static const char* TypeToString(Genre);
    static Genre StringToType(const char*);
};

