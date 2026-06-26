#include "Zoo.h"
#include "Animal.h"
#include "ZooKeeper.h"
#include <memory>

int main()
{
    //create a zoo with 3 different sections - one cage each for mammals and reptiles, and two cages for birds
    Zoo zoo;
    //add birds
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Bird, "Parrot Koko", 2));
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Bird, "Pigeon Doko", 2));
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Bird, "Sparrow Kuku", 1));
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Bird, "Sparrow Kiki", 1));
    //add reptiles
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Reptyle, "Lizard Miki", 2));
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Reptyle, "Snake Lucy", 3));
    //add mammals
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Mammal, "Elephant MyFrend", 44));
    zoo.addAnimal(std::make_shared<Animal>(AnimalType::Mammal, "Wolf Loupi", 3));
    //add zookeepers
    std::shared_ptr<ZooKeeper> ivan = zoo.addKeeper("Ivan", 0);
    std::shared_ptr<ZooKeeper> dragan = zoo.addKeeper("Dragan", 3);
    std::shared_ptr<ZooKeeper> petkan = zoo.addKeeper("Petkan", 5);
    //assign guards
    zoo.assignGuard(ivan, "Mammals"); //has no experience
    zoo.assignGuard(ivan, "Birds"); //ok
    zoo.assignGuard(dragan, "Mammals"); //ok
    zoo.assignGuard(petkan, "Reptiles"); //ok
    //print info
    zoo.printAll();
    //remove guard with id 1 - Ivan
    zoo.removeKeeper(1);
    //print info but this time with 1 guard less - bird section has none
    zoo.printAll();
    //search animals by name
    zoo.search("Snake Lucy");
    zoo.search("Snake Koko"); //there is not
    zoo.search("Parrot Koko");
}


/* explanation

---We use inheritance for Section -> BirdSection, MammalSection, ReptileSection.
These classes share common data(name, minimum experience, keeper, exhibits),
but differ in some things(different minimum experience and default exhibits).
Therefore, inheritance is appropriate.(is-a)

---Composition(has-a) is used for:
- Zoo has Sections and ZooKeepers
- Section has Exhibits
- Exhibit has Animals

---Rule of Zero :
We use the Rule of Zero because no manual resource management is used and
there are no raw pointers, new or delete.
*/