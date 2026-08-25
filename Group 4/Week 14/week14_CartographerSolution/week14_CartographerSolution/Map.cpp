#include "Map.h"

Map::Map(std::string title, Territory&& territory) : 
    title(std::move(title)), territory(std::make_shared<Territory>(std::move(territory)))
{
}

Map::Map(std::string title, std::shared_ptr<Territory> territory) :
    title(std::move(title)), territory(territory)
{
}

Map::Map(const Map& other) : title(other.title), 
    territory(std::make_shared<Territory>(*other.territory)),
    cartograhers(other.cartograhers), commandHistory()
{
}

Map& Map::operator=(const Map& other)
{
    if (this == &other) return *this;

    title = other.title;
    territory = std::make_shared<Territory>(*other.territory);
    cartograhers = other.cartograhers;

    return *this;
}

std::unique_ptr<Map> Map::unlink() const
{
    if (territory.use_count() <= 1) 
        throw std::invalid_argument("Cannot unlink a map that doesn't share any territories");

    return std::make_unique<Map>(*this);
}

void Map::addCartographer(std::shared_ptr<Cartographer> cartographer)
{
    cartograhers.push_back(std::move(cartographer));
}

void Map::execute(std::unique_ptr<Command> command)
{
    command->execute();
    commandHistory.push_back(std::move(command));
}

void Map::undo() 
{
    commandHistory[commandHistory.size() - 1]->undo();
    commandHistory.erase(commandHistory.begin() + (commandHistory.size() - 1));
}

void Map::printHistory() const
{
    const unsigned size = commandHistory.size();

    for (unsigned i = 0; i < size; i++)
    {
        commandHistory[i]->description();
    }
}

std::shared_ptr<Territory> Map::getTerritory() const
{
    return territory;
}

bool Map::isLinked() const
{
    return territory.use_count() > 1;
}

unsigned Map::useCount() const
{
    return territory.use_count();
}

const std::string& Map::getTitle() const
{
    return title;
}
