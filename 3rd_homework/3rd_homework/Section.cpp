#include "Section.h"
#include <stdexcept>
#include <print>
Section::Section(const std::string& inpName, unsigned inpMinExperience): name(inpName), minExperience(inpMinExperience)
{
}

void Section::addExhibit(const Exhibit& joiningExhibit)
{

	cages.push_back(joiningExhibit);
}

void Section::assignGuard(std::shared_ptr<Zookeeper> newGuard)
{
	if (newGuard->getExperience() < minExperience)
	{
		throw std::invalid_argument("The new guard does not have the minimum experience");
	}

	guard = newGuard;
}

bool Section::hasActiveGuard() const
{
	return !guard.expired();
}

void Section::printInfo() const
{
	std::println("Name: {}, minimum experience: {}", name, minExperience);

	for (const auto& cage : cages)
	{
		cage.print();
	}

}

const std::string& Section::getName() const
{
	return name;
}

bool Section::containsAnimal(const std::string& searchedName) const
{
	for (const auto& cage : cages)
	{
		if (cage.containsAnimal(searchedName))
			return true;
	}
	return false;
}
