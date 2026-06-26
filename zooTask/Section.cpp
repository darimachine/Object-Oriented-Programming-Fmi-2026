#include "Section.h"
#include "Exhibit.h"
#include "ZooKeeper.h"
#include <iostream>

Section::Section(const std::string& name, const size_t min_experience)
	: name(name), min_experience(min_experience)
{
	keeper = nullptr;
}

std::string Section::getName() const
{
	return name;
}

size_t Section::getMinExperience() const
{
	return min_experience;
}

bool Section::addExhibit(std::shared_ptr<Exhibit> exhibit)
{
	if (exhibit) {
		exhibits.push_back(exhibit);
		return true;
	}

	std::cout << "Error! An error occurred while adding a exhibit." << std::endl;

	return false;
}

bool Section::assignGuard(std::shared_ptr<ZooKeeper> newkeeper)
{
	if (newkeeper) {
		if (newkeeper->getExperience() >= getMinExperience()) {
			keeper = newkeeper;
			return true;
		}
		else {
			std::cout << "Error! The employee does not have enough experience." << std::endl;
		}
	}
	return false;
}

size_t Section::getKeeperId() const
{
	if (keeper) {
		return keeper->employeeId();
	}
	return 0;
}

void Section::removeGuard()
{
	if (keeper) {
		keeper.reset();
		std::cout << "The section's guard has been removed!" << std::endl;
	}
}

bool Section::hasActiveGuard() const
{
	if (keeper) {
		return true;
	}

	return false;
}

bool Section::addAnimal(std::shared_ptr<Animal> animal)
{
	if (animal) {
		for (auto& exhibit : exhibits) {
			if (exhibit && !exhibit->isFull()) {
				if (exhibit->addAnimal(animal)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Section::searchAnimal(const std::string& name) const
{
	bool find = false;
	if (!name.empty()) {
		for (auto& exhibit : exhibits) {
			if (exhibit) {
				find |= exhibit->searchAnimal(name);
			}
		}
	}
	return find;
}

std::ostream& operator<<(std::ostream& os, const Section* s)
{
	if (s) {
		os << "<< " << s->getName() << " | " << (s->hasActiveGuard() ? "there is active guard." : "no active guard!") << " >>" << std::endl;
		for (const auto& exhibit : s->exhibits) {
			if (exhibit) {
				os << *exhibit << std::endl;
			}
		}
	}

	return os;
}
