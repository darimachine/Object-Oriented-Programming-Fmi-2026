#include <iostream>
#include "Zoo.h"


void Zoo::addSection(std::unique_ptr<Section> s)
{
sections.push_back(std::move(s));
}

std::shared_ptr<ZooKeeper> Zoo::addKeeper(std::string name, int id, int exp)
{
    auto keeper = std::make_shared<ZooKeeper>(name, id, exp);
    keepers.push_back(keeper);
    return keeper;
}

void Zoo::removeKeeper(int id)
{
    auto keeperToErase = std::remove_if(keepers.begin(), keepers.end(), [id](auto k) { return k->getID() == id; });
    if (keeperToErase != keepers.end()) {
        for (auto& s : sections) {
            s->removeGuard();
        }
        keepers.erase(keeperToErase, keepers.end());
    }
}

void Zoo::printAll() const
{
    std::cout << "Zoo status: " << std::endl;
    for (const auto& s : sections) s->print();
}

void Zoo::search(std::string name) const
{
    std::cout << "Searching for '" << name << "':" << std::endl;
    for (const auto& s : sections) {
        for (const auto& e : s->getExhibit()) {
            for (const auto& a : e.getAnimals()) {
                if (a.getName() == name) {
                    std::cout << "  Found " << name << " in " << "Exhibit!" << std::endl;
                    return;
                }
            }
        }
    }
    std::cout << " Not found." << std::endl;
}

Section* Zoo::getSection(int index)
{
    return sections[index].get();
}
