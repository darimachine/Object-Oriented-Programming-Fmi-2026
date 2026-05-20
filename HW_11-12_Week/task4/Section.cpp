#include "Section.h"
#include "ZooException.h"
#include <iostream>

Section::Section(const std::string& name, int minExperience) : name(name), minExperience(minExperience)
{
	if (name.empty())
	{
		throw ZooException("Section name cannot be empty.");
	}
	if (minExperience < 0)
	{
		throw ZooException("Minimum experience cannot be negative.");
	}
}

void Section::addExhibit(const Exhibit& exhibit)
{
	exhibits.push_back(exhibit);
}

bool Section::assignGuard(const std::shared_ptr<ZooKeeper>& keeper)
{
    if (!keeper) return false;
    if (keeper->getYearsExperience() < minExperience) 
    {
        std::cout << "REJECTED: " << keeper->getName()
            << " has only " << keeper->getYearsExperience()
            << " yrs experience (min " << minExperience
            << " required for " << name << ")." << std::endl;
        return false;
    }
    guard = keeper;
    std::cout << "ASSIGNED: " << keeper->getName() << name << std::endl;
    return true;
}

bool Section::hasActiveGuard() const
{
    return !guard.expired();
}

int Section::getMinExp() const
{
    return minExperience;
}

const std::vector<Exhibit>& Section::getExhibits() const
{
    return exhibits;
}

const std::string& Section::getName() const 
{ 
    return name;
}

void Section::print() const
{
    std::cout << "" << sectionType() << " " << name << " | guard: ";

    if (hasActiveGuard()) 
    {
        std::cout << guard.lock()->getName();
    }
    else 
    {
        std::cout << "none";
    }

    std::cout << std::endl;

    for (size_t i = 0; i < exhibits.size(); i++) 
    {
        exhibits[i].print();
    }
}