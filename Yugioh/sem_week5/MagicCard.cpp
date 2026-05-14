#define _CRT_SECURE_NO_WARNINGS
#include "MagicCard.h"
#include <iostream>

MagicCard::MagicCard() : type(spell) 
{
    name[0] = '\0';
    effect[0] = '\0';
}
MagicCard::MagicCard(const char* name, const char* effect, MagicType type) : type(type) 
{
    strcpy(this->name, name);
    this->name[25] = '\0';
    strcpy(this->effect, effect);
    this->effect[100] = '\0';
}
void MagicCard::describeType() 
{
    std::cout << "Magic cards have a name, effect and a type." << std::endl;
}
void MagicCard::describeCard() const
{
    const char* typeStr;
    if (type == spell)
    {
        typeStr = "spell";
    }
    else if (type == equip)
    {
        typeStr = "equip";
    }
    else
    {
        typeStr = "trap";
    }
    std::cout << name << " is a " << typeStr << " with effect: " << effect << std::endl;
}
const char* MagicCard::getName() const 
{ 
    return name; 
}
const char* MagicCard::getEffect() const 
{ 
    return effect; 
}
MagicType   MagicCard::getType() const
{
    return type;
}