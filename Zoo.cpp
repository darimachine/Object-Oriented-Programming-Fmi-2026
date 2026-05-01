#include "Zoo.h"

shared_ptr<Guard> Zoo::addGuard(const Guard& g)
{
	auto it = find_if(guards.begin(), guards.end(),
		[&g](const shared_ptr<Guard>& other)
		{
			return g.getName() == other->getName();
		});

	if (it != guards.end())
	{
		return nullptr;
	}

	auto guard = make_shared<Guard>(g);
	guards.push_back(guard);
	return guard;
}

bool Zoo::removeGuard(unsigned employeeId)
{
	size_t oldSize = guards.size();

	erase_if(guards, [&employeeId](const shared_ptr<Guard>& g)
		{
			return g->getEmployeeId() == employeeId;
		});

	if (oldSize != guards.size())
	{
		return true;
	}
	return false;
}

void Zoo::printAll()const
{
	for (const auto& section : sections)
	{
		cout << section;
	}

	for (const auto& guard : guards)
	{
		cout << *guard;
	}
}

const Exhibit* Zoo::search(const string& animalName)const
{
	for (const auto& section : sections)
	{
		for (const auto& exhibit : section->getExhibits())
		{
			if (exhibit.getAnimalType() == animalName)
			{
				return &exhibit;
			}
		}
	}
	return nullptr;
}

Section& Zoo::addSection(const unique_ptr<Section>& section)
{
	auto it = find_if(sections.begin(), sections.end(),
		[&section](const unique_ptr<Section>& other)
		{
			return other->getName() == section->getName();
		});

	if (it != sections.end())
	{
		return **it;
	}
	sections.push_back(std::move(section));
	return *section;
}