#include<print>
#include<iostream>

enum class Type {
    Spell,
    Equip,
    Trap
};

class MonsterCard {
    char name[100] = "no name";
    unsigned int attackPoints = 0;
    unsigned int defensePoints = 0;

public:
    MonsterCard() = default;

    MonsterCard(const char *newName, const unsigned int newAttackPoints, const unsigned int newDefensePoints) {
        strcpy(this->name, newName);
        this->attackPoints = newAttackPoints;
        this->defensePoints = newDefensePoints;
    }

    const char *getName() const {
        return name;
    }

    unsigned int getAttackPoints() const {
        return attackPoints;
    }

    unsigned int getDefensePoints() const {
        return defensePoints;
    }

    void printCardInfo() const {
        std::print("Monster cards have a {} name, {} attack points and {} defense points \n",
                   getName(), getAttackPoints(), getDefensePoints());
    }

    void printCardInfoAnother() const {
        std::print("{} is a master with ATK: {} and DEF: {} \n",
                   getName(), getAttackPoints(), getDefensePoints());
    }
};

class MagicCard {
    char name[25 + 1] = "no name";
    char effect[100 + 1] = "no effect";
    Type type = Type::Spell;

public:
    MagicCard() = default;

    MagicCard(const char *newName, const char *newEffect, const Type newType) {
        strcpy(this->name, newName);
        strcpy(this->effect, newEffect);
        this->type = newType;
    }

    const char *getName() const {
        return name;
    }

    const char *getEffect() const {
        return effect;
    }

    void printType() const {
        switch (type) {
            case Type::Spell: std::print("Spell");
                break;
            case Type::Equip: std::print("Equip");
                break;
            case Type::Trap: std::print("Trap");
                break;
        }
    }

    void printCardInfo() const {
        std::print("Magic cards have a name {}, {} effect and a ",
                   getName(), getEffect());
        printType();
        std::print(" effect. \n");
    }

    void printCardInfoAnother() const {
        std::print("{} is a ", getName());
        printType();
        std::print(" with the following effect - \"{}\" \n", getEffect());
    }
};


constexpr int MAX_TYPE_SIZE = 20;

class Deck {
    MonsterCard monsterCards[MAX_TYPE_SIZE]{};
    MagicCard magicCards[MAX_TYPE_SIZE]{};
    int monsterCardsSize = 0;
    int magicCardsSize = 0;

public:
    int getCardsSize() const {
        return magicCardsSize + monsterCardsSize;
    }

    int getMagicCardsSize() const {
        return magicCardsSize;
    }

    int getMonsterCardsSize() const {
        return monsterCardsSize;
    }

    void addMagicCard(const char *newName, const char *newEffect, Type newType) {
        for (int i = 0; i < magicCardsSize; i++) {
            if (strcmp(monsterCards[i].getName(), newName) == 0) {
                std::print("Magic card with this name is already in the deck\n");
                return;
            }
        }

        magicCards[magicCardsSize] = MagicCard(newName, newEffect, newType);
        magicCardsSize++;
    }

    void addReadyMagicCard(const MagicCard &magicCard) {
        if (magicCardsSize == MAX_TYPE_SIZE) {
            std::println("Too many magic cards in the deck");
            return;
        }
        for (int i = 0; i < magicCardsSize; i++) {
            if (strcmp(magicCards[i].getName(), magicCard.getName()) == 0) {
                std::print("Magic card with this name is already in the deck\n");
                return;
            }
        }

        magicCards[magicCardsSize] = magicCard;
        magicCardsSize++;
    }

    void addMonsterCard(const char *newName, const int newAttackPoints, const int newDefensePoints) {
        for (int i = 0; i < monsterCardsSize; i++) {
            if (strcmp(monsterCards[i].getName(), newName) == 0) {
                std::print("Monster card with this name is already in the deck\n");
                return;
            }
        }

        monsterCards[monsterCardsSize] = MonsterCard(newName, newAttackPoints, newDefensePoints);
        monsterCardsSize++;
    }

    void addReadyMonsterCard(const MonsterCard &monsterCard) {
        if (monsterCardsSize == MAX_TYPE_SIZE) {
            std::println("Too many monster cards in the deck");
            return;
        }
        for (int i = 0; i < monsterCardsSize; i++) {
            if (strcmp(monsterCards[i].getName(), monsterCard.getName()) == 0) {
                std::print("Monster card with this name is already in the deck\n");
                return;
            }
        }

        monsterCards[monsterCardsSize] = monsterCard;
        monsterCardsSize++;
    }

    void changeMagicCard(const int position, const MagicCard &magicCard) {
        if (strcmp(magicCards[position].getName(), "no name") == 0) {
            magicCardsSize++;
        }

        magicCards[position] = magicCard;
        std::print("Magic card on {} position was changed\n", position);
    }

    void changeMonsterCard(const int position, const MonsterCard &monsterCard) {
        if (strcmp(monsterCards[position].getName(), "no name") == 0) {
            monsterCardsSize++;
        }

        monsterCards[position] = monsterCard;
        std::print("Monster card on {} position was changed\n", position);
    }

    void removeMagicCard(const int position) {
        for (int i = 0; i < magicCardsSize; i++) {
            if (i == position) {
                for (int j = i; j < magicCardsSize - 1; j++) {
                    magicCards[j] = magicCards[j + 1];
                }
                std::print("Magic card om position {} was removed\n", position);
                magicCardsSize--;
                return;
            }
        }

        std::print("There is no magic card on {} position\n", position);
    }

    void removeMonsterCard(const int position) {
        for (int i=0;i<monsterCardsSize;i++) {
            if (i == position) {
                for (int j=i; j<monsterCardsSize - 1; j++) {
                    monsterCards[j] = monsterCards[j + 1];
                }
                std::print("Magic card om position {} was removed\n", position);
                monsterCardsSize--;
                return;
            }
        }

        std::print("There is no monster card on {} position\n", position);
    }

    void printDeckInfo() const {
        std::print("Magic cards in deck: \n");
        for (int i = 0; i < magicCardsSize; i++) {
            magicCards[i].printCardInfoAnother();
        }

        std::print("Monster cards in deck: \n");
        for (int i = 0; i < monsterCardsSize; i++) {
            monsterCards[i].printCardInfoAnother();
        }
    }
};

class Duelist {
    char name[50] = "duelist";
    Deck deck;

public:
    Duelist() = default;

    explicit Duelist(const char* name) {
        strcpy(this->name, name);
    }

    const char* getName() const {
        return name;
    }

    Deck& getDeck() {
        return deck;
    }

    void changeMagicInDeck(const int position, const MagicCard &magicCard) {
        deck.changeMagicCard(position, magicCard);
    }

    void changeMonsterInDeck(const int position, const MonsterCard &monsterCard) {
        deck.changeMonsterCard(position,monsterCard);
    }

};

int main() {
    const MonsterCard monsterCard1("newMonsterCard1", 12, 53);
    // masterCard.printCardInfo();
    // masterCard.printCardInfoAnother();


    const MagicCard magicCard1("newMagicCard1", "newEffect1", Type::Trap);

    const MagicCard magicCard2("newMagicCard2", "newEffect2", Type::Spell);
    // magicCard.printCardInfo();
    // magicCard.printCardInfoAnother();

    Deck deck;
    deck.addReadyMagicCard(magicCard1);
    deck.addReadyMagicCard(magicCard2);
    deck.addReadyMonsterCard(monsterCard1);

    deck.printDeckInfo();

    const MagicCard magicCard3("newMagicCard3", "newEffect3", Type::Trap);
    const MonsterCard monsterCard2("newMonsterCard2", 43, 31);

    deck.changeMonsterCard(0,monsterCard2);
    deck.changeMonsterCard(1,monsterCard1);

    deck.changeMagicCard(2, magicCard3);

    std::cout<<std::endl;
    std::cout<<"New deck: "<<std::endl;

    deck.printDeckInfo();

    // READY TEST SOURCE

    // //40 cards = 20 MonsterCards/20 MagicCards
    // Deck d;
    //
    // // 4-th card in the Monster deck becomes "Yubel" with
    // //ATK: 0 DEF: 0
    // const MonsterCard monsterCard("Yubel", 0, 0);
    // d.changeMonsterCard(4, monsterCard);
    //
    // // 5-th card in the Magic deck is added/changed to "Pot of greed"
    // const MagicCard magicCard("Pot of greed", "Draw 2 cards.", Type::Spell);
    // d.changeMagicCard(5, magicCard);
    //
    // //Returns the amount of MagicCards in the deck
    // std::cout<<d.getMagicCardsSize()<<std::endl; //1
    //
    // //Returns the amount of MonsterCards in the deck
    // std::cout<<d.getMonsterCardsSize()<<std::endl; //1
    //
    // Duelist player1("Jaden Yuki");
    //
    // ///Changes the 2-nd monster card in the Monster deck to "Elemental HERO Neos"
    // const MonsterCard Neos("Elemental HERO Neos", 2500, 2000);
    // player1.changeMonsterInDeck(2, Neos);
    //
    // Duelist player2("Zane Truesdale");
    //
    // //Changes the 2-nd magic card in the Magic deck to "Monster Reborn"
    // const MagicCard MonsterReborn("Monster Reborn", "Revives a monster from the graveyard.", Type::Spell);
    // player2.changeMagicInDeck(2, MonsterReborn);
    //
    // std::cout<<std::endl;
    // std::cout<<player1.getName()<<"'s is: "<<std::endl;
    // player1.getDeck().printDeckInfo();
    //
    // std::cout<<std::endl;
    // std::cout<<player2.getName()<<"'s is: "<<std::endl;
    // player2.getDeck().printDeckInfo();

    return 0;
}
