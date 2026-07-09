#pragma once
#include<fstream>
#include"Utils.h"

class Package
{
private:
	Priority priority;
	double weight;
	std::string number;
	std::string receiver;


public:
	Package() = delete;
	Package(const std::string&, const std::string&, double, Priority);

	friend std::ostream& operator<<(std::ostream&, const Package&);
	auto operator<=>(const Package& other)const = default;

	const std::string& getTrackingNumber()const;
	const std::string& getReceiver()const;
	double getWeight()const;
	Priority getPriority()const;

	void setPriority(Priority priority);
};