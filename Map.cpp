#include "Map.h"
#include<stdexcept>
#include<iostream>

Map::Map(const string& title,Territory territory):
	title(title),territory(make_shared<Territory>(territory)){}

Map::Map(const string& title,shared_ptr<Territory> territory):
	title(title),territory(territory){}

Map::Map(const Map& other):territory(make_shared<Territory>(*other.territory)),
cartographers(other.cartographers){}

Map& Map::operator=(const Map& other)
{
	if (this != &other)
	{
		territory = make_shared<Territory>(*other.territory);
		cartographers = other.cartographers;
		history.clear();
	}
	return *this;
}

const string& Map::getTitle() const
{
	return title;
}

void Map::setTitle(const string& newTitle)
{
	title = newTitle;
}

bool Map::isLinked() const
{
	return territory.use_count() > 1;
}

void Map::unlink()
{
	if (!isLinked())
	{
		return;
	}
	territory = make_shared<Territory>();
	history.clear();
}

void Map::addCartographer(shared_ptr<Cartographer> c)
{
	cartographers.push_back(move(c));
}

void Map::execute(unique_ptr<Command> command)
{
	command->execute();
	history.push_back(move(command));
}

void Map::undo()
{
	if (history.empty())
	{
		throw runtime_error("The history is empty.");
	}
	history.back()->undo();
	history.pop_back();
}

void Map::printHistory() const
{
	for (const auto& command : history)
	{
		cout << command->description() << '\n';
	}
}

size_t Map::useCount() const
{
	return territory.use_count();
}

shared_ptr<Territory> Map::getTerritory() const
{
	return territory;
}

void Map::print()
{
	cout << "Territory:" << '\n';
	territory->print();

	cout << "Cartographers:" << '\n';
	for (const auto& c : cartographers)
	{
		c->print();
	}
}

 