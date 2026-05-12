#pragma once
#include <string>
#include <iostream>
class CarPart
{
	static size_t idGen;
	size_t id;
	std::string manufacturerName = "Unknown manufacturer";
	std::string description = "No description";

protected:
	std::ostream& printBase(std::ostream& os) const;

public:
	CarPart(std::string manufacturerName, std::string description);

	size_t getId() const;
	void setManufacturer(std::string manufacturerName);
	const std::string& getManufacturer() const;
	void setDescription(std::string description);
	const std::string& getDescription() const;

	friend std::ostream& operator<<(std::ostream& os, const CarPart& cp);
};

