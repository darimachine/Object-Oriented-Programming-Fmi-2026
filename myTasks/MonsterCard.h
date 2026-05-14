#pragma once
class MonsterCard
{
    private:
        char* name = nullptr;
        unsigned int attackP;
        unsigned int deffendP;

        void free();
        void copyFrom(const MonsterCard&);
    public:
        MonsterCard();
        MonsterCard(const char*, unsigned int, unsigned int);
        ~MonsterCard();
        MonsterCard(const MonsterCard&);
        MonsterCard& operator=(const MonsterCard&);

        void setName(const char* );
        unsigned int getAttakP() const;
        unsigned int getDeffendP() const;
        const char* getName() const;
        void printInfoGeneral() const;
        void printSpecificInfo() const;
};


