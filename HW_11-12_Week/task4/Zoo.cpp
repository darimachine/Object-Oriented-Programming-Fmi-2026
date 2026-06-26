#include "Zoo.h"
#include "ZooException.h"
#include <iostream>

void Zoo::addSection(std::unique_ptr<Section> section)
{
	sections.push_back(std::move(section));
}

std::shared_ptr<ZooKeeper> Zoo::addKeeper(const std::string& name, unsigned id, int exp)
{
	std::shared_ptr<ZooKeeper> keeper = std::make_shared<ZooKeeper>(name, id, exp);
	keepers.push_back(keeper);
	return keeper;
}

void Zoo::removeKeeper(unsigned employeeID)
{
	auto keeperToRemove = std::find_if(keepers.begin(), keepers.end(),
		[employeeID](const std::shared_ptr<ZooKeeper>& keeper)
		{
			return keeper->getID() == employeeID;
		});

	if (keeperToRemove == keepers.end())
	{
		throw ZooException("Keeper with this ID is not found.");
	}

	std::cout << "REMOVED " << (*keeperToRemove)->getName() << std::endl;
	keepers.erase(keeperToRemove);
}

void Zoo::printAll() const
{
	for (const auto& sec : sections)
	{
		sec->print();
	}
}

const Animal* Zoo::search(const std::string& name) const
{
	for (const auto& section : sections)
	{
		for (const auto& ex : section->getExhibits())
		{
			for (const auto& animal : ex.getAnimals()) 
			{
				if (animal.getName() == name)
				{
					return &animal;
				}
			}
		}
	}
	return nullptr;
}
