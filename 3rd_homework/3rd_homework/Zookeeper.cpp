#include "Zookeeper.h"
#include <print>
unsigned int Zookeeper::ID = 1;
Zookeeper::Zookeeper(const std::string& inpName, unsigned int inpMinExperience) 
	: name(inpName), experience(inpMinExperience)
{
	personalID = ID;
	ID++;
}

unsigned int Zookeeper::getExperience() const
{
	return experience;
}

unsigned int Zookeeper::getPersonalID() const
{
	return personalID;
}

void Zookeeper::print() const
{
	std::println("Name: {}, personalID: {}, experience: {}", name, personalID, experience);
}
