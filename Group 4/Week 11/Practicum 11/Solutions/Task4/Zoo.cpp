#include "Zoo.h"
#include <iostream>
#include <algorithm>

void Zoo::addSection(std::unique_ptr<Section> s) 
{ 
    sections.push_back(std::move(s));
}

std::shared_ptr<ZooKeeper> Zoo::addKeeper(std::string name, int exp) {
    auto keeper = std::make_shared<ZooKeeper>(name, exp);
    keepers.push_back(keeper);
    return keeper;
}

void Zoo::removeKeeper(int id) {
    std::erase_if(keepers, [id](const auto& keeper) { return keeper->getID() == id; });
}

Section* Zoo::getSection(size_t index) 
{ 
    return sections.at(index).get(); 
}

void Zoo::printAll() const {
    for (const auto& sec : sections)
    {
        std::cout << "\nSection: " << sec->getName() << " [Has keeper: " << (sec->hasActiveGuard() ? "Yes" : "No") << "]\n";
        for (const auto& ex : sec->getExhibits())
        {
            std::cout << "  - Exhibit at " << ex.getLocation() << " for " << ex.getAnimalType() << "s\n";
            for (const auto& a : ex.getAnimals()) 
            {
                std::cout << "    * " << a.getName() << " (" << a.getAge() << " years)\n";
            }
        }
    }
}

void Zoo::search(const std::string& name) const {
    std::cout << "Searching for '" << name << "':\n";
    for (const auto& sec : sections) {
        for (const auto& ex : sec->getExhibits()) 
        {
            for (const auto& a : ex.getAnimals()) 
            {
                if (a.getName() == name)
                {
                    std::cout << "Found " << name << " (a " << a.getType() << ") in section " << sec->getName() << "\n";
                }
            }
        }
    }
}