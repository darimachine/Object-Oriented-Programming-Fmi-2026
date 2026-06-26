#include <iostream>
#include "Cartographer.h"
#include "Landmark.h"
#include "LandmarkFactory.h"
#include "Territory.h"
#include "Command.h"
#include "CommandFactory.h"
#include "Map.h"
#include "Curator.h"
#include "FieldSurveyor.h"
#include "Archivist.h"
#include "ExpeditionLeader.h"

int main() {
    try {
        auto ivan = std::make_shared<FieldSurveyor>("Ivan", 5, "Thrace");
        auto maria = std::make_shared<Archivist>("Maria", 12, "National Library");
        auto petar = std::make_shared<ExpeditionLeader>("Petar", 8, 4);

        auto ashfields = std::make_shared<Territory>(4);

        ashfields->addLandmark(LandmarkFactory::create("settlement", "Oakhaven", { 12.5, 45.1 }, 2, "1500"));
        ashfields->addLandmark(LandmarkFactory::create("dungeon", "Shadow Tomb", { 13.0, 44.8 }, 7, "5"));

        Curator curator;
        Map& north = curator.addLinkedMap("Northern Survey", ashfields);
        Map& south = curator.addLinkedMap("Southern Survey", ashfields);

        north.addCartographer(ivan);
        north.addCartographer(maria);

        south.addCartographer(ivan);
        south.addCartographer(petar);

        north.execute(CommandFactory::create("add", "ruin;Ancient Temple;10.0;20.0;6;Incas", north.getTerritory()));

        std::cout << "Does Southern Survey see 'Ancient Temple'? -> "
            << (south.getTerritory().hasLandmark("Ancient Temple") ? "YES" : "NO") << "\n";

        Map copy = north;

        std::cout << "Territory use_count: " << north.useCount() << "\n";
        std::cout << "Cartographer 'Ivan' use_count: " << ivan.use_count() << "\n";

        copy.execute(CommandFactory::create("danger", "9", copy.getTerritory()));
        std::cout << "Did Northern Survey detect the danger level change?: " << north.getTerritory().getDangerLevel() << "\n";

        Map& expCopy = curator.copyAsIndependent("Northern Survey", "Expedition copy");

        std::cout << "Original Territory use_count (shouldn't be changed): " << north.useCount() << "\n";
        std::cout << "Cartographer 'Ivan' use_count (should increase because they are shared): " << ivan.use_count() << "\n";

        expCopy.execute(CommandFactory::create("add", "natural;Red Forest;5.0;5.0;3;Forest", expCopy.getTerritory()));

        std::cout << "Does Expedition copy have 'Red Forest'? -> " << (expCopy.getTerritory().hasLandmark("Red Forest") ? "YES" : "NO") << "\n";
        std::cout << "Does Northern Survey have 'Red Forest'? -> " << (north.getTerritory().hasLandmark("Red Forest") ? "YES" : "NO") << " (Expected: NO)\n";

        expCopy.undo();
        std::cout << "After Undo : Does Expedition copy still have 'Red Forest'? -> " << (expCopy.getTerritory().hasLandmark("Red Forest") ? "YES" : "NO") << " (Expected: NO)\n";

        std::cout << "Territory use_count before unlink: " << north.useCount() << "\n";

        north.unlink();

        std::cout << "Territory use_count after unlink: " << north.useCount() << "\n";
        std::cout << "Are cartographers unaffected? 'Ivan' use_count: " << ivan.use_count() << " (shouldn't be changed)\n";

    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Validation error: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << "\n";
    }

    return 0;
}