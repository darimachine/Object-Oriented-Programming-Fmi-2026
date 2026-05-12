#pragma once
#include <string>
#include <iostream>

class ZooKeeper {

	std::string name;
	size_t id;
	size_t experience;

public:

	ZooKeeper(const size_t _id, const std::string& _name, const size_t _experience);
	std::string getName() const;
	size_t employeeId() const;
	size_t getExperience() const;

	friend std::ostream& operator<<(std::ostream& os, const ZooKeeper& k);
};

