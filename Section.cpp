#include "Section.h"

Section::Section(const string& name, int minExperience):
	name(name),minExperience(minExperience),guard(nullptr){ }

bool Section::addExhibit(const Exhibit& e)
{
	auto it = find_if(exhibits.begin(), exhibits.end(),
		[&e](const Exhibit& other)
		{
			return e.getLocation() == other.getLocation();
		});

	if (it != exhibits.end())
	{
		return false;
	}

	exhibits.push_back(e);
	return true;
}

void Section::assignGuard(Guard* g)
{
	guard = g;
}

bool Section::hasActiveGuard()const
{
	return guard != nullptr;
}

ostream& operator<<(ostream& os, const Section& s)
{
	os << s.name << " " << s.minExperience << '\n';
	for (const auto& exhibit : s.exhibits)
	{
		os << exhibit;
	}

	if (s.guard)
	{
		os << *s.guard << '\n';
	}
	else
	{
		os << "No guard assigned!" << '\n';
	}

	return os;
}

const vector<Exhibit>& Section::getExhibits()const
{
	return exhibits;
}

const string& Section::getName()const
{
	return name;
}

Exhibit* Section::findExhibit(const string& animalType)
{
	auto it = find_if(exhibits.begin(), exhibits.end(),
		[&animalType](const Exhibit& e)
		{
			return e.getAnimalType() == animalType;
		});

	if (it == exhibits.end())
	{
		return nullptr;
	}

	return &(*it);
}