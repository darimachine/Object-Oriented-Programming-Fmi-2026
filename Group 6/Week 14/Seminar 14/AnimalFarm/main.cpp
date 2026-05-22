#include "AnimalFarm.h"
#include "Pig.h"
#include "Cow.h"
#include "Sheep.h"

int main() {
    AnimalFarm animalFarm;
    Pig peppaPig("Peppa the Pig");
    Cow cow("Milka");
    Sheep sheep("Dolly");
    std::unique_ptr<Animal> pig = std::make_unique<Pig>("Piglet");

    animalFarm.addAnimal(peppaPig);
    animalFarm.addAnimal(pig);
    animalFarm.addAnimal(cow);
    animalFarm.addAnimal(sheep);

    try {
        animalFarm.addAnimal(nullptr);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    animalFarm.wakeUpAnimals();

    AnimalFarm animalFarm2 = animalFarm;
    animalFarm2.wakeUpAnimals();
}
