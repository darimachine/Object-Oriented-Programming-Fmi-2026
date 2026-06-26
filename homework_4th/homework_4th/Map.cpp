#include "Map.h"

Map::Map(std::shared_ptr<Territory> initialTerritory) : territory(std::move(initialTerritory))
{
}

Map::Map(const Map& other) : territory(other.territory), cartographers(other.cartographers)
{
}

void Map::unlink()
{
	if (isLinked())
	{
		territory = std::make_shared<Territory>(*territory);
		history.clear();
	}
}

void Map::addCartographer(std::shared_ptr<Cartographer> joiningCart)
{
	cartographers.push_back(std::move(joiningCart));
}

void Map::execute(std::unique_ptr<Command> command)
{
	if (command)
	{
		command->execute();
		history.push_back(std::move(command));
	}
}

void Map::undo()
{
	if (!history.empty())
	{
		history.back()->undo();
		history.pop_back();
	}
}

bool Map::isLinked() const
{
	return territory.use_count() > 1;
}

long Map::useCount() const
{
	return territory.use_count();
}

Territory& Map::getTerritory() const
{
	return *territory;
}

void Map::print() const
{
	territory->print();
}

void Map::printHistory() const
{
	for (const auto& cmd : history)
	{
		std::cout << cmd->description() << '\n';
	}
}
