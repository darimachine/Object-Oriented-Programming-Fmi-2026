#include "Warehouse.h"

Warehouse::Warehouse(const std::string& name, size_t capacity) :name(name), capacity(capacity) {}

bool Warehouse::addPackage(const std::string& trackingNum, const std::string& recipient, double weight, Priority priority)
{
	if (capacity == packages.size())
	{
		return false;
	}

	if (PackageValidator::checkPackages(packages, trackingNum))
	{
		return false;
	}

	//auto p = std::make_unique<Package>(trackingNum, recipient, weight, priority);
	//packages.push_back(p);
	packages.emplace_back(std::make_unique<Package>(trackingNum, recipient, weight, priority));
	return true;
}

void Warehouse::removePackage(const std::string& trackingNum)
{
	std::erase_if(packages, [&trackingNum](const std::unique_ptr<Package>& package)
		{
			return package->getTrackingNumber() == trackingNum;
		});
}

Package* Warehouse::operator[](const std::string& trackingNum)
{
	auto it = std::find_if(packages.begin(), packages.end(), [&trackingNum](const std::unique_ptr<Package>& package)
		{
			return package->getTrackingNumber() == trackingNum;
		});

	if (it == packages.end())
	{
		return nullptr;
	}

	return it->get();
}

const Package* Warehouse::operator[](const std::string& trackingNum)const
{
	auto it = std::find_if(packages.begin(), packages.end(), [&trackingNum](const std::unique_ptr<Package>& package)
		{
			return package->getTrackingNumber() == trackingNum;
		});

	if (it == packages.end())
	{
		return nullptr;
	}

	return it->get();
}

bool Warehouse::transferTo(const std::string& trackingNum, Warehouse& other)
{
	if (other.capacity == other.packages.size())
	{
		return false;
	}

	Package* package = (*this)[trackingNum];

	if (package == nullptr)
	{
		return false;
	}

	bool added = other.addPackage(package->getTrackingNumber(), package->getReceiver(),
		package->getWeight(), package->getPriority());

	if (added)
	{
		removePackage(trackingNum);
	}

	return added;
}

Package* Warehouse::heaviestPackage()const
{
	if (packages.empty())
	{
		return nullptr;
	}

	auto it = std::max_element(packages.begin(), packages.end(),
		[](const std::unique_ptr<Package>& a, const std::unique_ptr<Package>& b)
		{
			return a->getWeight() < b->getWeight();
		});

	return it->get();
}

unsigned Warehouse::urgentPackages()const
{
	if (packages.empty())
	{
		return 0;
	}

	unsigned count = 0;
	for (const auto& i : packages)
	{
		if (i->getPriority() == Priority::URGENT)
		{
			count++;
		}
	}
	return count;
}

double Warehouse::totalWeight()const
{
	double total = 0.0;
	for (const auto& i : packages)
	{
		total += i->getWeight();
	}

	return total;
}

std::ostream& operator<<(std::ostream& os, const Warehouse& w)
{
	for (const auto& i : w.packages)
	{
		os << *i;
	}
	return os;
}

Warehouse::operator bool()const
{
	return packages.size() > capacity * PERCENTAGE;
}

Warehouse& Warehouse::operator()(const std::string& trackingNum, Priority priority)
{
	Package* package = (*this)[trackingNum];

	if (package)
	{
		package->setPriority(priority);
	}
	return *this;
}
