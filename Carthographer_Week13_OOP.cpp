#include <iostream>
#include"Cartographer.h"
#include"Curator.h"
#include"LandmarkFactory.h"
#include"CommandFactory.h"
#include"ExpeditionLeader.h"
#include"FieldSurveyor.h"
#include"Archivist.h"

int main() {
    Curator registry;

    auto carto1 = make_shared<ExpeditionLeader>("Alex", 10, 5);
    auto carto2 = make_shared<FieldSurveyor>("Mira", 14, "Africa");
    auto carto3 = make_shared<Archivist>("Martin", 5, "Explore");

    auto sharedTerritory = make_shared<Territory>();
    sharedTerritory->addLandmark(LandmarkFactory::create("Settlement", "Ashford", Coordinates{ 10, 20 }, 3, "500"));
    sharedTerritory->addLandmark(LandmarkFactory::create("Dungeon", "Darkhold", Coordinates{ 15, 25 }, 7, "3"));

    Map& north = registry.addLinkedMap("Northern Survey", sharedTerritory);
    Map& south = registry.addLinkedMap("Southern Survey", sharedTerritory);

    north.addCartographer(carto1);
    north.addCartographer(carto2);
    south.addCartographer(carto2);
    south.addCartographer(carto3);

    std::cout << "=== After creation ===\n";
    std::cout << "use_count of the territory: " << sharedTerritory.use_count() << "\n";

    north.execute(CommandFactory::createCommand("add", "Ruin Sunken Spire 30 40 5 Elven", *north.getTerritory()));
    south.print();

    Map copy = north;
    std::cout << "use_count of the territory: " << sharedTerritory.use_count() << "\n"; 
    std::cout << "copy isLinked: " << copy.isLinked() << "\n"; 
    
    north.execute(CommandFactory::createCommand("set", "6", *north.getTerritory()));
    copy.print();
    south.print();

    Map& expedition = registry.copyAsIndependent("Northern Survey", "Expedition Copy");

    std::cout << "\n=== After copyAsIndependent ===\n";
    std::cout << "use_count of the shared territory: " << sharedTerritory.use_count() << "\n";
    std::cout << "expedition isLinked: " << expedition.isLinked() << "\n"; 
    std::cout << "carto1 use_count: " << carto1.use_count() << "\n"; 

    expedition.execute(CommandFactory::createCommand("add", "NaturalFeature Crystal Grove 50 60 2 Waterfall", *expedition.getTerritory()));

    north.print();
    expedition.print();

    expedition.undo();
    expedition.print();
    expedition.printHistory();

    std::cout << "use_count before: " << north.useCount() << "\n";
    north.unlink();
    std::cout << "use_count after:  " << north.useCount() << "\n";
    std::cout << "north isLinked: " << north.isLinked() << "\n"; 
    std::cout << "carto1 use_count: " << carto1.use_count() << "\n";

    return 0;
}

