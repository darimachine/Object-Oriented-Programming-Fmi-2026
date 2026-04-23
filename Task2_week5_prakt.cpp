#include <iostream>
#include"Duelist.h"

int main()
{
    MonsterCard m1("White Dragon", 3000, 2500);
    MonsterCard m2("Dark Magician", 2500, 2100);

    MagicCard c1("Pot of Greed", "Draw 2 cards.", "spell");
    MagicCard c2("Mirror Force", "Destroy all attack position monsters.", "trap");

    MonsterCard::describeType();
    MagicCard::describeType();

    std::println();

    m1.printInfo();
    c1.printInfo();

    std::println();

    Deck deck;

    deck.addMonsterCard(m1);
    deck.addMonsterCard(m2);

    deck.addMagicCard(c1);
    deck.addMagicCard(c2);

    std::println("Monster cards count: {}", deck.countMonsterCards());
    std::println("Magic cards count: {}", deck.countMagicCards());

    std::println();

    MonsterCard m3("Black Dragon", 2400, 2000);
    deck.changeMonsterCard(0, m3);

    deck.removeMagicCard(1);

    std::println("After changes:");
    std::println("Monster cards count: {}", deck.countMonsterCards());
    std::println("Magic cards count: {}", deck.countMagicCards());

    std::println();

    Duelist d("Ivan");

    d.addMonsterCardInDeck(m1);
    d.addMagicCardInDeck(c1);

    std::println("Duelist deck:");
    std::println("Monster cards: {}", d.getMonsterCardsCount());
    std::println("Magic cards: {}", d.getMagicCardsCount());
    
    d.changeMagicCardInDeck(0, c2);

    d.removeMonsterCardInDeck(0);

    std::println("After Duelist changes:");
    std::println("Monster cards: {}", d.getMonsterCardsCount());
    std::println("Magic cards: {}", d.getMagicCardsCount());

    return 0;
}

