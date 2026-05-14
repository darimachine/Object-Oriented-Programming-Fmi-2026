#pragma once
enum MagicType 
{
	spell,
	equip,
	trap 
};
class MagicCard
{
private:
    static const int MAX_NAME = 26;
    static const int MAX_EFFECT = 101;
    char name[MAX_NAME];
    char effect[MAX_EFFECT];
    MagicType type;

public:
    MagicCard();
    MagicCard(const char* name, const char* effect, MagicType type);
    static void describeType();
    void describeCard() const;
    const char* getName() const;
    const char* getEffect() const;
    MagicType getType() const;
};

