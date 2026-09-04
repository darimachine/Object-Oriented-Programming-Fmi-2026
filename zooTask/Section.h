#pragma once
#include <string>
#include <vector>
#include <memory>

class Exhibit;
class ZooKeeper;
class Animal;

class Section
{
	std::string name;
	size_t min_experience;
	std::shared_ptr<ZooKeeper> keeper;
	std::vector<std::shared_ptr<Exhibit>> exhibits;

public:
	Section(const std::string& name, const size_t min_experience);

	std::string getName() const;
	size_t getMinExperience() const;

	virtual bool addExhibit(std::shared_ptr<Exhibit> exhibit);
	bool assignGuard(std::shared_ptr<ZooKeeper> newkeeper);
	size_t getKeeperId() const;
	void removeGuard();
	bool hasActiveGuard() const;
	bool addAnimal(std::shared_ptr<Animal> animal);
	bool searchAnimal(const std::string& name) const;

	friend std::ostream& operator<<(std::ostream& os, const Section* s);
};

