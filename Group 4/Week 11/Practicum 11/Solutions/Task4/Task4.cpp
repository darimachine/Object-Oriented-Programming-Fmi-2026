#include <iostream>
#include "Zoo.h"

int main() {
    Zoo myZoo;

    myZoo.addSection(std::make_unique<BirdSection>());
    myZoo.addSection(std::make_unique<MammalSection>());
    myZoo.addSection(std::make_unique<ReptileSection>());

    Exhibit birdEx("High Trees", "Eagle");
    birdEx.addAnimal(Animal("Aquila", "Eagle", 4));
    birdEx.addAnimal(Animal("Icarus", "Eagle", 2));

    Exhibit mammalEx("Grassy Plains", "Lion");
    mammalEx.addAnimal(Animal("Simba", "Lion", 5));

    Exhibit reptileEx("Desert Heat", "Cobra");
    reptileEx.addAnimal(Animal("Nagini", "Cobra", 8));

    myZoo.getSection(0)->addExhibit(birdEx);
    myZoo.getSection(1)->addExhibit(mammalEx);
    myZoo.getSection(2)->addExhibit(reptileEx);

    auto apprentice = myZoo.addKeeper("Stefan", 2); 
    auto expert = myZoo.addKeeper("Maria", 10);  

    std::cout << "--- Testing Guard Assignment ---" << std::endl;

    bool check1 = myZoo.getSection(1)->assignGuard(apprentice);
    std::cout << "Assigning Stefan (2y) to Mammal (3y req): "
        << (check1 ? "SUCCESS" : "DENIED") << std::endl;

    bool check2 = myZoo.getSection(2)->assignGuard(expert);
    std::cout << "Assigning Maria (10y) to Reptile (5y req): "
        << (check2 ? "SUCCESS" : "DENIED") << std::endl;

    bool check3 = myZoo.getSection(0)->assignGuard(apprentice);
    std::cout << "Assigning Stefan (2y) to Bird (0y req): "
        << (check3 ? "SUCCESS" : "DENIED") << std::endl;

    std::cout << "\nReptile Section has active guard: " << std::boolalpha
        << myZoo.getSection(2)->hasActiveGuard() << std::endl;

    std::cout << "\nRemoving Expert Guard (Maria) from the Zoo..." << std::endl;
    myZoo.removeKeeper(expert->getID());


    std::cout << "Reptile Section guard status after removal: "
        << myZoo.getSection(2)->hasActiveGuard() << std::endl;


    std::cout << "\n--- Testing Search ---" << std::endl;
    myZoo.search("Simba");
    myZoo.search("Nemo"); 

    std::cout << "\n--- FULL ZOO AUDIT ---" << std::endl;
    myZoo.printAll();

    return 0;
}