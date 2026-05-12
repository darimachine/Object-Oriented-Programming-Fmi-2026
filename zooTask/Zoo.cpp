#include "Zoo.h"

Zoo::Zoo()
{
	initSections();
}

std::shared_ptr<ZooKeeper> Zoo::addKeeper(const std::string name, const size_t experience)
{
	std::shared_ptr<ZooKeeper> keeper(new ZooKeeper((keepers.size()+1), name, experience));
	keepers.push_back(keeper);

	return keeper;
}

bool Zoo::removeKeeper(const size_t id)
{
	if (!id) return false;

		size_t count = 0;
		for (auto& keeper : keepers) {
			if (keeper) {
				if (keeper->employeeId() == id) {
					if (b_section && b_section->getKeeperId() == id) {
						b_section->removeGuard();
					}
					if (m_section && m_section->getKeeperId() == id) {
						m_section->removeGuard();
					}
					if (r_section && r_section->getKeeperId() == id) {
						r_section->removeGuard();
					}
					keepers.erase(keepers.begin() + count);
					return true;
				}
			}
			count++;
		}

	return false;
}

bool Zoo::assignGuard(std::shared_ptr<ZooKeeper> keeper, const std::string& section)
{
	if (keeper) {
		if (section == "Birds") {
			if (b_section) {
				return b_section->assignGuard(keeper);
			}
		}
		else if(section == "Mammals"){
			if (m_section) {
				return m_section->assignGuard(keeper);
			}
		}
		else if (section == "Reptiles") {
			if (r_section) {
				return r_section->assignGuard(keeper);
			}
		}
	}
	return false;
}

void Zoo::printAll() const
{
	std::cout << "<<< Employees >>>" << std::endl;
	for (const auto& keeper : keepers) {
		if (keeper) {
			std::cout << *keeper << std::endl;
		}
	}
	std::cout << "<<< Sections >>>" << std::endl;
	if (b_section) {
		std::cout << *b_section << std::endl;
	}
	if (r_section) {
		std::cout << *r_section << std::endl;
	}
	if (m_section) {
		std::cout << *m_section << std::endl;
	}
}

void Zoo::search(const std::string& name) const
{
	bool find = false;
	if (!name.empty()) {
		if (b_section) {
			find |= b_section->searchAnimal(name);
		}
		if (r_section) {
			find |= r_section->searchAnimal(name);
		}
		if (m_section) {
			find |= m_section->searchAnimal(name);
		}
	}
	if (!find) {
		std::cout << "The animal named " << name << " was not found!" << std::endl;
	}
}

bool Zoo::addAnimal(std::shared_ptr<Animal> animal)
{
	bool result = false;
	if (animal) {
		switch (animal->getType()) {
		case AnimalType::Bird: {
			if (b_section) {
				result = b_section->addAnimal(animal);
			}
			break;
		}
		case AnimalType::Reptyle: {
			if (r_section) {
				result = r_section->addAnimal(animal);
			}
			break;
		}
		case AnimalType::Mammal: {
			if (m_section) {
				result = m_section->addAnimal(animal);
			}
			break;
		}
		default: break;
		}
	}
	return result;
}

void Zoo::initSections()
{
	b_section = std::make_unique<BirdSection>("Birds");
	m_section = std::make_unique<MammalSection>("Mammals");
	r_section = std::make_unique<ReptileSection>("Reptiles");
}
