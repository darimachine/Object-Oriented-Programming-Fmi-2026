#include "Map.h"

Map::Map(const std::string& _title, std::shared_ptr<Territory> _territory):title(_title), territory(_territory) {}

Map::Map(const Map& other)
{
    this->title = other.title;
    this->territory = other.territory;
    this->cartographers = other.cartographers;
    this->history.clear();
}

void Map::unlink()
{
    if (isLinked()) {
        this->territory = std::make_shared<Territory>(*this->territory);
        this->history.clear();
    }
}

void Map::addCartographer(const std::shared_ptr<Cartographer> c)
{
    cartographers.push_back(c);
}

void Map::execute(std::unique_ptr<Command> com)
{
    if (com)
    {
        com->execute();
        history.push_back(std::move(com));
    }
}

void Map::undo()
{
    if (history.empty()) {
        std::cout << "No left commands to undo.\n";
        return;
    }
    history.back()->undo();
    history.pop_back();
}

void Map::printHistory() const
{
    std::cout << "Editting history for map: " << title << "\n";
    if (history.empty())
    {
        std::cout << " (No edits made yet)\n";
        return;
    }
    for (int i = 0; i < history.size(); i++)
    {
        std::cout << i + 1 << ". " << history[i]->description() << "\n";
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

void Map::print() const
{
    std::cout << "Title of map: " << title << "\n";
    std::cout << "Is it linked: " << (isLinked() ? "YES" : "NO") << " (Shared by " << useCount() << " maps)\n";
    std::cout << "Cartographers involved\n";
    for (const auto& c : cartographers) {
        c->print();
    }
    std::cout << "Territory details\n";
    territory->print();
}

std::string Map::getTitle() const
{
    return title;
}

void Map::setTitle(const std::string& newTitle)
{
    title = newTitle;
}
