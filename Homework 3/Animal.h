#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <optional>
class Animal
{
protected:
	std::string name;
	std::string type;
	unsigned int age;
public:
	Animal(std::string _name, std::string _type, unsigned int age);
	std::string getType() const;
	void print() const;
	std::string getName() const;
};

class Exhibit {
protected:
	std::string location;
	std::string type;
	static unsigned int id;
	unsigned int count;
	unsigned int capacity;
	std::vector<std::unique_ptr<Animal>> collection;
public:
	Exhibit(std::string _location,std::string _type, unsigned int _capacity);
	void addAnimal(Animal& an);
	bool isFull();
	void print() const;
	std::vector<std::unique_ptr<Animal>> getCollection() const;
};

struct Keeper {
	std::string name;
	unsigned int experience;
	static int count;
	int employeeID;
	Keeper(std::string name, unsigned int _experience);
	int getID() const;
	void print() const;
};

class Section {
protected:
	std::string name;
	unsigned int exp;
	std::vector<std::unique_ptr<Exhibit>> collEx;
	std::weak_ptr<Keeper> guard;
public:
	void addExhibit(Exhibit& ex);
	virtual void assignKeeper(std::shared_ptr<Keeper> keeper);
	bool hasActiveKeeper();
	virtual ~Section();
	std::string getName() const;
	Section();
	std::weak_ptr<Keeper> getKeeper() const;
	void removeEmployee(int employeeID);
	void print() const;
	std::optional<Animal&> getAnimal(std::string name);

};

class BirdSection : public Section {
public:
	void assignKeeper(std::shared_ptr<Keeper> keeper) override;
	BirdSection();

};
class MammulSection : public Section {
public:
	void assignKeeper(std::shared_ptr<Keeper> keeper) override;
	MammulSection();

};

class ReptileSection : public Section {
public:
	void assignKeeper(std::shared_ptr<Keeper> keeper) override;
	ReptileSection();

};

class Zoo {
	Zoo();
	BirdSection bird;
	MammulSection mammul;
	ReptileSection reptile;
public:
	Zoo(const Zoo& zoo) = delete;
	Zoo(Zoo&& zoo) = delete;
	static Zoo& getInstance();
	std::shared_ptr<Keeper> addKeeper(std::shared_ptr<Keeper> keep, Section& section);
	void removeKeeper(int employeeID);
	void print();
	std::optional<Animal&> getAnimal(std::string name);
};
