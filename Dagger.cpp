#include "Dagger.h"
#include "DaggerNotRetrievedException.h"
#include <random>
#include <stdexcept>

static std::mt19937 daggerEngine{ std::random_device{}() };

Dagger::Dagger(const std::string& name) :Weapon(name), thrown(false) {}

int Dagger::roll()const
{
	if (thrown)
	{
		throw DaggerNotRetrievedException("Rogue");
	}
	std::uniform_int_distribution<int> dist{ 1, 20 };
	return dist(daggerEngine);
}

void Dagger::pickUp()
{
	thrown = false;
}

int Dagger::throwDagger()
{
	if (thrown)
	{
		throw std::logic_error("Dagger already thrown!");
	}

	thrown = true;
	std::uniform_int_distribution<int> dist{ 5, 30 };
	return dist(daggerEngine);
}
