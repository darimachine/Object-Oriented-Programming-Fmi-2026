#include "Zoo.h"

#include <iostream>

#include "BirdSection.h"
#include "MammalSection.h"
#include "ReptileSection.h"

int main() {

    auto keeper = std::make_shared<ZooKeeper>("richard", "castle", 5);
    auto keeper2 = std::make_shared<ZooKeeper>("antoni", "ivanov", 1);
    auto keeper3 = std::make_shared<ZooKeeper>("georgi", "salparov", 10);


    Exhibit exhibit1("1 kletka do vhoda", "lyv", 0, 5);
    exhibit1.addAnimal("leo", "lyv", 5);
    exhibit1.addAnimal("nio", "lyv", 2);
    // MammalSection mammalSection;
    auto mammalSection = std::make_unique<MammalSection>("leos");
    (*mammalSection).addExhibit(std::move(exhibit1));

    Exhibit exhibit2("2 kletka sreshtu vhoda", "zmiq", 0, 10);
    exhibit2.addAnimal("klo", "zmiq", 10);
    exhibit2.addAnimal("plo", "zmiq", 4);
    auto reptile = std::make_unique<ReptileSection>("snakes");
    (*reptile).addExhibit(std::move(exhibit2));

    Exhibit exhibit3("3 kletka v sgradata", "papagal", 0, 8);
    exhibit3.addAnimal("rio", "papapgal", 1);
    exhibit3.addAnimal("moy", "papagal", 5);
    // BirdSection birdSection;
    auto birdSection = std::make_unique<BirdSection>("birds", *keeper);
    (*birdSection).addExhibit(std::move(exhibit3));

    Zoo zoo;
    zoo.addSection(std::move(reptile));
    zoo.addSection(std::move(birdSection));
    zoo.addSection(std::move(mammalSection));


    zoo.printAll();

    std::cout << "\n";
    std::cout << "####################### \n";
    std::cout << "\n";


    // modify


    // ZooKeeper keeper("richard", "castle", 5);
    // ZooKeeper keeper2("antoni", "ivanov", 1);
    // ZooKeeper keeper3("georgi", "salparov", 10);

    zoo.addKeeper(*keeper);
    zoo.addKeeper(*keeper2);
    zoo.addKeeper(*keeper3);


    std::cout << std::boolalpha << (*birdSection).hasActiveGuard() << "\n";

    // std::cout << std::boolalpha << zoo.addKeeper() << "\n";

    // birdSection->assignGuard(keeper);

    // try {
    //     birdSection->assignGuard(keeper);
    // } catch (const std::exception& e) {
    //     std::cout << e.what() << "\n";
    // }

    // try {
    //     reptile->assignGuard(std::move(keeper2));
    // } catch (const std::exception& e) {
    //     std::cout << e.what() << "\n";
    // }
}