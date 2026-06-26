#include <iostream>
#include "Zoo.h"
#include "BirdSection.h"
#include "MammalSection.h"
#include "ReptileSection.h"
#include "ZooException.h"

int main()
{
    try 
    {
        Zoo zoo;
        auto birds = std::make_unique<BirdSection>("Aviary");
        auto mammals = std::make_unique<MammalSection>("Savannah");
        auto reptiles = std::make_unique<ReptileSection>("Reptile House");

        Exhibit eagleExhibit("East Wing A", "Eagle", 3);
        eagleExhibit.addAnimal(Animal("Eddie", "Eagle", 4));
        eagleExhibit.addAnimal(Animal("Elara", "Eagle", 2));
        birds->addExhibit(eagleExhibit);

        Exhibit lionExhibit("Savannah North", "Lion", 2);
        lionExhibit.addAnimal(Animal("Leo", "Lion", 6));
        mammals->addExhibit(lionExhibit);

        Exhibit snakeExhibit("Terrarium 1", "Cobra", 4);
        snakeExhibit.addAnimal(Animal("Sable", "Cobra", 3));
        reptiles->addExhibit(snakeExhibit);

        zoo.addSection(std::move(birds));
        zoo.addSection(std::move(mammals));
        zoo.addSection(std::move(reptiles));

        auto junior = zoo.addKeeper("Alice", 101, 1);
        auto senior = zoo.addKeeper("Bob", 102, 7);

        zoo.printAll();

        ReptileSection rep2("Demo Reptiles");
        rep2.assignGuard(junior);
        rep2.assignGuard(senior); 

        std::cout << "hasActiveGuard after assign: " << std::boolalpha << rep2.hasActiveGuard() << std::endl;

        zoo.removeKeeper(102); 
        std::cout << "hasActiveGuard after removeKeeper: " << rep2.hasActiveGuard() << "\n";

        zoo.printAll();

        const Animal* found = zoo.search("Leo");
        if (found) 
        {
            std::cout << "Search found: ";
            found->print();
        }

        const Animal* notFound = zoo.search("Nemo");
        std::cout << "Search 'Nemo': ";
        if (notFound) 
        {
            std::cout << "found";
        }
        else 
        {
            std::cout << "not found";
        }
        std::cout << std::endl;

    }
    catch (const ZooException& exception)
    {
        std::cout << "Zoo error: " << exception.what() << std::endl;
    }
    catch (const std::exception& exception)
    {
        std::cout << "Error: " << exception.what() << std::endl;
    }
}