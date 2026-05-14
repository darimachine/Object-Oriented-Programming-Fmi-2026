#define _CRT_SECURE_NO_WARNINGS
#include "Jedi.h"
#include "JediUtils.h"

const char* colorToString(SaberColor color) 
{
    switch (color) 
    {
    case SaberColor::RED:
        return "RED";
    case SaberColor::YELLOW:
        return "YELLOW";
    case SaberColor::GREEN:
        return "GREEN";
    case SaberColor::BLUE:
        return "BLUE";
    case SaberColor::PURPLE:
        return "PURPLE";
    default:
        return "UNKNOWN";
    }
}

const char* typeToString(SaberType type) 
{
    switch (type) 
    {
    case SaberType::SINGLE_BLADED:
        return "SINGLE_BLADED";
    case SaberType::DOUBLE_BLADED:
        return "DOUBLE_BLADED";
    case SaberType::CROSSGUARD:
        return "CROSSGUARD";
    default:
        return "UNKNOWN";
    }
}