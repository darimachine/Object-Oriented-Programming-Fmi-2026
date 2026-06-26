#pragma once
#include <string>
class Zookeeper
{
	private:
		std::string name;
		static unsigned int ID;
		unsigned int personalID;
		unsigned int experience;

	public:
		Zookeeper(const std::string& inpName, unsigned int inpMinExperience);

		unsigned int getExperience() const;
		unsigned int getPersonalID() const;

		void print() const;
};

