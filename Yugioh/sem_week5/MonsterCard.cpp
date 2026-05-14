#define _CRT_SECURE_NO_WARNINGS
#include "MonsterCard.h"
MonsterCard::MonsterCard() : name(nullptr), atk(0), def(0) 
{

}
MonsterCard::MonsterCard(const char* name, unsigned int atk, unsigned int def) : atk(atk), def(def) 
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
void MonsterCard::copyFrom(const MonsterCard& other)
{
    if (other.name)
    {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else
    {
        name = nullptr;
    }
    atk = other.atk;
    def = other.def;
}
void MonsterCard::free()
{
    delete[] name;
    name = nullptr;
}
MonsterCard::MonsterCard(const MonsterCard& other)
{
    copyFrom(other);
}
MonsterCard& MonsterCard::operator=(const MonsterCard& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}
MonsterCard::~MonsterCard()
{
    free();
}
void MonsterCard::describeType() 
{
    cout << "Monster cards have name, attack point and defense point." << endl;
}
void MonsterCard::describeCard() const 
{
    if (name) 
    {
        std::cout << "`" << name << "` is a monster with ATK: " << atk << " and DEF: " << def << "." << std::endl;
    }
    else 
    {
        std::cout << "`Unknown` is a monster with ATK: " << atk << " and DEF: " << def << "." << std::endl;
    }
}
const char* MonsterCard::getName() const 
{
    return name;
}
unsigned int MonsterCard::getATK() const 
{
    return atk; 
}
unsigned int MonsterCard::getDEF() const
{ 
    return def;
}