#include "Map.h"
#include <iostream>

Map::Map(const std::string& title, std::shared_ptr<Territory> territory) : title(title), territory(std::move(territory))
{

}

Map::Map(const Map& other) : title(other.title), territory(other.territory), cartographers(other.cartographers)
{

}

Map& Map::operator=(const Map& other)
{
    if (this != &other) 
    {
        title = other.title;
        territory = other.territory;
        cartographers = other.cartographers;
        history.clear();
    }
    return *this;
}

void Map::unlink()
{
    if (territory.use_count() > 1) 
    {
        territory = std::make_shared<Territory>(*territory);
        history.clear();
    }
}

void Map::addCartographer(std::shared_ptr<Cartographer> cartographer)
{
    cartographers.push_back(std::move(cartographer));
}

void Map::execute(std::unique_ptr<Command> command)
{
    command->execute();
    history.push_back(std::move(command));
}

void Map::undo() 
{
    if (history.empty()) 
    {
        throw std::runtime_error("Nothing to undo.");
    }
    history.back()->undo();
    history.pop_back();
}

void Map::printHistory() const
{
    std::cout << "History for " << title << " (" << history.size() << " entries):" << std::endl;
    for (std::size_t i = 0; i < history.size(); ++i)
    {
        std::cout << "[" << (i + 1) << "]" << history[i]->description() << std::endl;
    }
}

void Map::print() const {
    std::cout << "Map: " << title << " | territory: " << territory.use_count() << std::endl;
    territory->print();
    std::cout << "Cartographers (" << cartographers.size() << "):" << std::endl;
    for (const auto& cartographer : cartographers)
    {
        std::cout << "  ";
        cartographer->print();
    }
}

Territory& Map::getTerritory()
{
    return *territory;
}

const Territory& Map::getTerritory() const
{
    return *territory;
}

bool Map::isLinked() const
{
    return territory.use_count() > 1;
}

long Map::useCount() const
{
    return territory.use_count();
}

const std::string& Map::getTitle() const
{
    return title;
}

void Map::setTitle(const std::string& title)
{
    this->title = title;
}

const std::vector<std::shared_ptr<Cartographer>>& Map::getCartographers() const
{
    return cartographers;
}

