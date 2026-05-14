#pragma once;
constexpr  int MAX_LEN_NAME = 25;
constexpr  int MAX_EFFECT_LEN = 100;

enum  class type
{
    SPELL,
    EQUIP,
    TRAP
};
class MagicCard
{
    private:
        char name[MAX_LEN_NAME + 1];
        char effect[MAX_EFFECT_LEN + 1];
        type magicType;
    public:
        MagicCard();
        MagicCard( const char* , const char*, type MagicType);

        void setName(const char*);
        void setEffect(const char* );
        void setMagicType(type&);

        const char* getName() const;
        const char* getEffect() const;
        const char* getType() const;

        void printInfoGeneral() const;
        void printInfoSpecific() const;

};

