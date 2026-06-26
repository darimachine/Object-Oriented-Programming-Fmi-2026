#pragma once
#include <string>
#include <vector>
#include "Exhibit.h"
#include "Zookeeper.h"
#include <memory>
class Section
{
		protected:
		std::string name;
		unsigned minExperience;
		std::vector <Exhibit> cages;
		std::weak_ptr<Zookeeper> guard;

	public:
		Section(const std::string& inpName, unsigned inpMinExperience);
		void addExhibit(const Exhibit& joiningExhibit);
		void assignGuard(std::shared_ptr<Zookeeper> newGuard);
		bool hasActiveGuard() const;

		virtual void printInfo() const;

		const std::string& getName() const;

		bool containsAnimal(const std::string& searchedName) const;

};

