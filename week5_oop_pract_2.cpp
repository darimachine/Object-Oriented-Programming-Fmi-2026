#include <iostream>
#include "Duelist.h"

int main()
{
    //40 cards = 20 MonsterCards/20 MagicCards
    Deck d;

    // 4-th card in the Monster deck becomes "Yubel" with
    //ATK: 0 DEF: 0
    d.changeMonster(4, "Yubel", 0, 0);

    // 5-th card in the Magic deck is added/changed to "Pot of greed"
    d.changeMagic(5, "Pot of greed", "Draw 2 cards.", "spell");

    //Returns the amount of MagicCards in the deck
    d.getMagicsCount(); //1

    //Returns the amount of MonsterCards in the deck
    d.getMonstersCount(); //1

    Duelist player1("Jaden Yuki");

    ///Changes the 2-nd monster card in the Monster deck to "Elemental HERO Neos"
    MonsterCard Neos("Elemental HERO Neos", 2500, 2000);
    player1.changeMonster(2, Neos);

    Duelist player2("Zane Truesdale");

    //Changes the 2-nd magic card in the Magic deck to "Monster Reborn"
    MagicCard MonsterReborn("Monster Reborn", "Revives a monster from the graveyard.", Type::spell);
    player2.changeMagic(2, MonsterReborn);
}

