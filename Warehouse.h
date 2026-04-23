#pragma once
#include"PackageValidator.h"

class Warehouse
{
private:
	static constexpr size_t DEFAULT_CAPACITY = 16;
	static constexpr double PERCENTAGE = 0.80;

	std::string name;
	size_t capacity = DEFAULT_CAPACITY;
	std::vector<std::unique_ptr<Package>> packages;

public:
	Warehouse() = delete;
	Warehouse(const std::string& name, size_t capacity);

	bool addPackage(const std::string& trackingNum, const std::string& recipient, double weight, Priority priority);
	void removePackage(const std::string& trackingNum);

	Package* operator[](const std::string& trackingNum);
	const Package* operator[](const std::string& trackingNum) const;

	bool transferTo(const std::string& trackingNum, Warehouse& other);
	Package* heaviestPackage()const;
	unsigned urgentPackages()const;
	double totalWeight()const;

	friend std::ostream& operator<<(std::ostream& os, const Warehouse& w);
	operator bool()const;
	Warehouse& operator()(const std::string& trackingNum, Priority priority);
};
