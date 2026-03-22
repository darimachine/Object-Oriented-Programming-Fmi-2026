#include  <iostream>
#include  <cstring>
#include "MagicCard.h"

MagicCard::MagicCard()
{
    name[0] ='\0';
    effect[0] ='\0';
    magicType = type::TRAP;
}

MagicCard::MagicCard(const char *name, const char *effect, type MagicType)
{
    setName(name);
    setEffect(effect);
    setMagicType(MagicType);
}

void MagicCard::setName(const char *name)
{
    if (name == nullptr)
    {
        this->name[0] = '\0';
        return;
    }
    else
    {
        int inpNameLen = strlen(name);
        if (inpNameLen > MAX_LEN_NAME)
        {
            this->name[0] = '\0';
            return;
        }
        else
        {
            strcpy(this->name, name);
            this->name[inpNameLen] = '\0';
        }
    }
}

void MagicCard::setEffect(const char *effect)
{
    if(effect == nullptr)
    {
        this->effect[0] = '\0';
        return;
    }
    else
    {
        int inpEffectLen = strlen(effect);
        if (inpEffectLen > MAX_EFFECT_LEN)
        {
            this->effect[0] = '\0';
            return;
        }
        else
        {
            strcpy(this->effect, effect);
            this->effect[inpEffectLen] = '\0';
        }
    }
}

void MagicCard::setMagicType(type &MagicType)
{
    this->magicType = MagicType;
}

void MagicCard::printInfoGeneral() const
{
    std::println("Magic cards have a name, effect and a type - spell, equip or trap.");
}

const char *MagicCard::getName() const
{
    return  name;
}

const char *MagicCard::getEffect() const
{
    return  effect;
}

const char *MagicCard::getType() const
{
    switch (magicType)
    {
        case type::TRAP:
            return  "trap";
        case type::EQUIP:
            return "equip";
        case type::SPELL:
            return "spell";
    }
}

void MagicCard::printInfoSpecific() const
{
    std::println("{} is a {} with the following effect - {} ", getName(), getType(), getEffect());
}

// int main()
// {
//
//
//
//     return 0;
// }