#include  <iostream>
#include  <cstring>
#include  <print>
#include "MonsterCard.h"

MonsterCard::MonsterCard(): name(nullptr), deffendP(0), attackP(0)
{}

MonsterCard::MonsterCard(const char *name, unsigned int attackP, unsigned int deffendP)
{
    setName(name);
    this->attackP = attackP;
    this->deffendP = deffendP;
}

void MonsterCard::setName(const char *name)
{
    delete [] this->name;
    if (name == nullptr)
    {
        this->name =nullptr;
        attackP = 0;
        deffendP = 0;
        return;
    }
    size_t inpNameLen = strlen(name);
    this->name =  new char[inpNameLen + 1];
    strcpy(this->name, name);
}

void MonsterCard::free()
{
    delete [] name;
    name = nullptr;
}

void MonsterCard::copyFrom(const MonsterCard &other)
{
    if (other.name == nullptr)
    {
        this->name = nullptr;
        attackP = 0;
        deffendP =0;
        return;
    }
    else
    {
        size_t otherNameLen = strlen(other.name);
        name = new char[otherNameLen + 1];
        strcpy(name, other.name);
        attackP = other.attackP;
        deffendP = other.deffendP;
    }
}

MonsterCard::~MonsterCard()
{
    free();
}

MonsterCard::MonsterCard(const MonsterCard &other)
{
    copyFrom(other);
}

MonsterCard &MonsterCard::operator=(const MonsterCard &other)
{
    if (this != &other)
    {
            free();
            copyFrom(other);
    }
    return  *this;
}

unsigned int MonsterCard::getAttakP() const
{
    return  attackP;
}

unsigned int MonsterCard::getDeffendP() const
{
    return deffendP;
}

const char *MonsterCard::getName() const
{
    return name? name: "";
}

void MonsterCard::printInfoGeneral() const
{
    std::println("Monster cards have a name, attack points and defense points");

}

void MonsterCard::printSpecificInfo() const
{
    std::println("{} is a monster with ATK: {} and DEF: {}", getName(), getAttakP(), getDeffendP());
}

// int main()
// {
//
//  return  0;
// }