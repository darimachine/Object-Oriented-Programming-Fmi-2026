#include <iostream>
#include "MonsterCard.h"
#include "MagicCard.h"
#include "Deck.h"
#include "Duelist.h"

int main()
{
	MonsterCard blueEyes("Blue-Eyes White Dragon", 3000, 2500);
	MonsterCard darkMagician("Dark Magician", 2500, 2100);
	MonsterCard kuriboh("Kuriboh", 300, 200);
	blueEyes.describeCard();
	darkMagician.describeCard();
	kuriboh.describeCard();
	MagicCard potOfGreed("Pot of Greed", "Draw 2 cards.", spell);
	MagicCard darkHole("Dark Hole", "Destroys all monsters on the field.", spell);
	MagicCard mirrorForce("Mirror Force", "Destroy all attacking monsters.", trap);
	potOfGreed.describeCard();
	darkHole.describeCard();
	mirrorForce.describeCard();
	Deck deck;
	deck.addMonsterCard(blueEyes);
	deck.addMonsterCard(darkMagician);
	deck.addMonsterCard(kuriboh);
	deck.addMagicCard(potOfGreed);
	deck.addMagicCard(darkHole);
	deck.addMagicCard(mirrorForce);
	std::cout << "Monster count: " << deck.getMonsterCardCount() << std::endl;
	std::cout << "Magic count:   " << deck.getMagicCardCount() << std::endl;
	Duelist yugi("Yugi Muto");
	Duelist kaiba("Seto Kaiba");
	yugi.addMonsterCard(darkMagician);
	yugi.addMagicCard(potOfGreed);
	kaiba.addMonsterCard(blueEyes);
	kaiba.addMagicCard(darkHole);
	std::cout << yugi.getName() << std::endl;
	std::cout << "Monsters: " << yugi.getMonsterCardCount() << std::endl;
	std::cout << "Magic: " << yugi.getMagicCardCount() << std::endl;
	std::cout << kaiba.getName() << std::endl;
	std::cout << "Monsters: " << kaiba.getMonsterCardCount() << std::endl;
	std::cout << "Magic: " << kaiba.getMagicCardCount() << std::endl;
	deck.changeMonsterCard(1, "Summoned Skull", 2500, 1200);
	deck.changeMagicCard(1, "Monster Reborn", "Revives a monster.", spell);
	deck.removeMonsterCard(0);
	deck.removeMagicCard(0);
	std::cout << "Monster count: " << deck.getMonsterCardCount() << std::endl;
	std::cout << "Magic count: " << deck.getMagicCardCount() << std::endl;
}
