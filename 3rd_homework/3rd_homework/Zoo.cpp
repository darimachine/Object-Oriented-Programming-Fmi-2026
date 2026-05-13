#include "Zoo.h"
#include <algorithm>
#include <print>
#include <iostream>
std::shared_ptr<Zookeeper> Zoo::addKeeper(const std::string& inpNam, unsigned inpMinExperience)
{
    auto newKeeper = std::make_shared<Zookeeper>(inpNam, inpMinExperience);

    guards.push_back(newKeeper);

    return newKeeper;
}

void Zoo::removeKeeper(unsigned employeeID)
{
    std::erase_if(guards, [employeeID](const auto& currKeeper)
        {return currKeeper->getPersonalID() == employeeID; });
}

void Zoo::addSection(std::unique_ptr<Section> joiningSection)
{
    sections.push_back(std::move(joiningSection));
}

void Zoo::printAll() const
{
    for (const auto& currGuard : guards)
    {
        currGuard->print();
    }

    for (const auto& currSecton : sections)
    {
        currSecton->printInfo();
    }
}

void Zoo::search(const std::string& name) const
{
    for (const auto& section : sections)
    {
        if (section->containsAnimal(name))
        {
            std::println("The animal: {} has been found", name);
            return;
        }
    }
    std::println("The animal: {} has not been found", name);
}
