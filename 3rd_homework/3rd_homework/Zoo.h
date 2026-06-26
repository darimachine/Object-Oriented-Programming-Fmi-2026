#pragma once
#include "Section.h"
#include "Zookeeper.h"
#include <memory>
class Zoo
{
	private:
		std::vector<std::unique_ptr<Section>> sections;
		std::vector<std::shared_ptr<Zookeeper>> guards;

	public:
		std::shared_ptr<Zookeeper> addKeeper(const std::string& inpNam, unsigned inpMinExperience);
		void removeKeeper(unsigned employeeID);
		void addSection(std::unique_ptr<Section> joiningSection);
		void printAll() const;
		void search(const std::string& name) const;
};

