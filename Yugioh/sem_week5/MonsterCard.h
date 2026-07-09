#pragma once
#include <iostream>
using namespace std;

class MonsterCard
{
private:
    char* name;
    unsigned int atk;
    unsigned int def;
    void copyFrom(const MonsterCard& other);
    void free();
public:
    MonsterCard();
    MonsterCard(const char* name, unsigned int atk, unsigned int def);
    MonsterCard(const MonsterCard& other);
    MonsterCard& operator=(const MonsterCard& other);
    ~MonsterCard();
    static void describeType();
    void describeCard() const;
    const char* getName() const;
    unsigned int getATK() const;
    unsigned int getDEF() const;
};

