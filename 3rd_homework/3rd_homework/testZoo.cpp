#include <iostream>
#include "Zoo.h"
#include "MammalSection.h"
#include "BirdSection.h"
#include "ReptileSection.h"
int main()
{

	try
	{
		Zoo myZoo;

		Exhibit parrotCage("First cage", "Parrot", 5);
		parrotCage.addAnimal(Animal("Choko", 2, "Parrot"));
		parrotCage.addAnimal(Animal("Rio", 7, "Parrot"));

		Exhibit lionCage("Second cage", "Lion", 7);
		lionCage.addAnimal(Animal("Poli", 12, "Lion"));

		Exhibit snakeCage("Third cage", "Snake", 2);
		snakeCage.addAnimal(Animal("gnus", 1, "Snake"));

		auto mammalSec = std::make_unique<MammalSection>("Mammals");
		auto birdSec = std::make_unique<BirdSection>("Birds");
		auto reptileSec = std::make_unique<ReptileSection>("Reptiles");

		mammalSec->addExhibit(lionCage);
		birdSec->addExhibit(parrotCage);
		reptileSec->addExhibit(snakeCage);

		auto firstGuard = myZoo.addKeeper("Rosti", 1);
		try
		{
			mammalSec->assignGuard(firstGuard);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';


			auto secondGuard = myZoo.addKeeper("Nasko", 10);
			mammalSec->assignGuard(secondGuard);
			std::cout << mammalSec->hasActiveGuard();

			myZoo.removeKeeper(secondGuard->getPersonalID());
			std::cout << mammalSec->hasActiveGuard();

			myZoo.addSection(std::move(mammalSec));
			myZoo.addSection(std::move(birdSec));
			myZoo.addSection(std::move(reptileSec));

			myZoo.printAll();
			myZoo.search("Rio");
			myZoo.search("Nemo");
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;

}
