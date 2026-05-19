#include"Zoo.h"
#include"BirdSection.h"
#include"MammalSection.h"
#include"ReptileSection.h"

int main() {
    Zoo zoo;

    auto& birds = zoo.addSection(make_unique<BirdSection>("North Wing",2));
    auto& mammals = zoo.addSection(make_unique<MammalSection>("Safari Zone"));
    auto& reptiles = zoo.addSection(make_unique<ReptileSection>("Reptile House"));

    birds.addExhibit(Exhibit("Cage A1", "Parrot", 5));
    birds.addExhibit(Exhibit("Cage A2", "Eagle", 2));
    mammals.addExhibit(Exhibit("Cage B1", "Lion", 4));
    reptiles.addExhibit(Exhibit("Cage C1", "Cobra", 3));

    birds.findExhibit("Parrot")->addAnimal();
    birds.findExhibit("Parrot")->addAnimal();
    mammals.findExhibit("Lion")->addAnimal();
    reptiles.findExhibit("Cobra")->addAnimal();

    auto junior = zoo.addGuard(Guard("Ivan", 1));
    auto senior = zoo.addGuard(Guard("Maria", 6));

    try {
        reptiles.assignGuard(junior.get());
        cout << "ERROR: should have thrown!\n";
    }
    catch (const exception& e) {
        cout << "Caught: " << e.what() << "\n";
    }

    reptiles.assignGuard(senior.get());
    cout << "Reptile has guard: " << boolalpha << reptiles.hasActiveGuard() << "\n"; // true

    birds.assignGuard(junior.get());
    cout << "Birds has guard: " << birds.hasActiveGuard() << "\n"; // true

    zoo.removeGuard(2);
    cout << "Reptile has guard after remove: " << reptiles.hasActiveGuard() << "\n"; // false

    zoo.printAll();

    const Exhibit* found = zoo.search("Lion");
    if (found)
    {
        cout << "Found: " << found->getAnimalType()
            << " in " << found->getLocation() << "\n";
    }
    else
    {
        cout << "Lion: not found.\n";
    }

    found = zoo.search("Dragon");
    if (!found)
    {
        cout << "Dragon: not found.\n";
    }

    return 0;
}