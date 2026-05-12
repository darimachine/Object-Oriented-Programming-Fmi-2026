#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include "BirdSection.h"
#include "MammalSection.h"
#include "ReptileSection.h"
#include "ZooKeeper.h"
#include "Animal.h"

class Zoo
{
	void initSections();

	std::vector<std::shared_ptr<ZooKeeper>> keepers;
	std::unique_ptr<BirdSection> b_section;
	std::unique_ptr<MammalSection> m_section;
	std::unique_ptr<ReptileSection> r_section;

public:

	Zoo();
	std::shared_ptr<ZooKeeper> addKeeper(const std::string name, const size_t experience);
	bool removeKeeper(const size_t id);

	bool assignGuard(std::shared_ptr<ZooKeeper> keeper, const std::string& section);
	bool addAnimal(std::shared_ptr<Animal> animal);
	void printAll() const;
	void search(const std::string& name) const;
};

