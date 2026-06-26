#include "Animal.h"
int Keeper::count = 1;
Animal::Animal(std::string _name, std::string _type, unsigned int _age)
	:name(_name), type(_type), age(_age)
{

}

std::string Animal::getType() const
{
	return type;
}

void Animal::print() const
{
	std::cout << "Name: " << name << ", Type: " << type << ", Age: " << age << std::endl;
}

std::string Animal::getName() const
{
	return name;
}

Exhibit::Exhibit(std::string _location, std::string _type, unsigned int _capacity)
	:location(_location), type(_type), capacity(_capacity)
{
}

void Exhibit::addAnimal(Animal& an)
{
	if (!isFull()) {
		if (an.getType() == type) {
			std::unique_ptr<Animal> animal = std::make_unique<Animal>(std::move(an));
			collection.push_back(animal);
		}
	}
}

bool Exhibit::isFull()
{
	if (collection.size() == capacity) {
		return 1;
	}
	return 0;
}

void Exhibit::print() const
{
	std::cout << "Type: " << type;

	for(auto i=collection.begin(); i<=collection.end();i++)	{
		(*i)->print();
	}
}

std::vector<std::unique_ptr<Animal>> Exhibit::getCollection() const
{
	return collection;
}

void Section::addExhibit(Exhibit& ex)
{
	std::unique_ptr<Exhibit> exhibit = std::make_unique<Exhibit>(ex);
	collEx.push_back(exhibit);
}

void Section::assignKeeper(std::shared_ptr<Keeper> keeper)
{
	if (keeper->experience >= exp) {
		guard = keeper;
	}
}

bool Section::hasActiveKeeper()
{
	return !guard.expired();
}

Section::~Section()
{
}

std::string Section::getName() const
{
	return name;
}

Section::Section() : name(), exp(), collEx(), guard()
{
}

std::weak_ptr<Keeper> Section::getKeeper() const
{
	return guard;
}

void Section::removeEmployee(int employeeID)
{
	if (auto k = guard.lock()) {
		if (k->getID() == employeeID) {
			guard.reset();
		}
	}
}

void Section::print() const
{
	std::cout << "Section Name: " << name << ", Required Experience: " << exp << std::endl;
	for (auto i = collEx.begin(); i <= collEx.end();i++) {
		(*i)->print();
	}
	auto i = guard.lock();
	(i)->print();
}

std::optional<Animal&> Section::getAnimal(std::string name)
{
	for (auto i = collEx.begin(); i <= collEx.end();i++) {
		for (auto j = (*i)->getCollection().begin(); j <= (*i)->getCollection().end();j++) {
			if ((*j)->getName() == name) {
				return *(*j);
			}
		}
	}
	return std::nullopt;
}

void BirdSection::assignKeeper(std::shared_ptr<Keeper> keeper)
{
	exp = 0;
	Section::assignKeeper(keeper);
}

BirdSection::BirdSection(): Section()
{
}

void MammulSection::assignKeeper(std::shared_ptr<Keeper> keeper)
{
	exp = 3;
	Section::assignKeeper(keeper);
}

MammulSection::MammulSection(): Section()
{
}

void ReptileSection::assignKeeper(std::shared_ptr<Keeper> keeper)
{
	exp = 5;
	Section::assignKeeper(keeper);
}

ReptileSection::ReptileSection() : Section()
{
}


Keeper::Keeper(std::string _name, unsigned int _experience)
	:name(_name), experience(_experience)
{
	employeeID = count;
	count++;
}

int Keeper::getID() const
{
	return employeeID;
}

void Keeper::print() const
{
	std::cout << "Name: " << name << ", Experience: " << experience << ", Employee ID: " << employeeID << std::endl;
}

// Zoo.cpp
Zoo::Zoo()
	: bird(), mammul(), reptile()
{
}

Zoo& Zoo::getInstance() {
	static Zoo instance;
	return instance;
}

std::shared_ptr<Keeper> Zoo::addKeeper(std::shared_ptr<Keeper> keep, Section& section)
{
	if (section.getName() == "BirdSection") {
		Zoo::bird.assignKeeper(keep);
	}
	if (section.getName() == "MammulSection") {
		Zoo::mammul.assignKeeper(keep);
	}
	if (section.getName() == "ReptileSection") {
		Zoo::reptile.assignKeeper(keep);
	}
	return keep;
}

void Zoo::removeKeeper(int employeeID)
{
	if (auto k = Zoo::bird.getKeeper().lock()) {
		bird.removeEmployee(employeeID);
	}
	if (auto k = Zoo::mammul.getKeeper().lock()) {
		mammul.removeEmployee(employeeID);
	}
	if (auto k = Zoo::reptile.getKeeper().lock()) {
		reptile.removeEmployee(employeeID);
	}
}

void Zoo::print()
{
	std::cout << "Zoo Information:" << std::endl;
	std::cout << "Bird Section:" << std::endl;
	bird.print();
	std::cout << "Mammul Section:" << std::endl;
	mammul.print();
	std::cout << "Reptile Section:" << std::endl;
	reptile.print();
}

std::optional<Animal&> Zoo::getAnimal(std::string name)
{
	if (auto animal = bird.getAnimal(name)) {
		return animal;
	}
	if (auto animal = mammul.getAnimal(name)) {
		return animal;
	}
	if (auto animal = reptile.getAnimal(name)) {
		return animal;
	}
	return std::nullopt;
}

