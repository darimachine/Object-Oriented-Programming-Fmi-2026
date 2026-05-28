#include "Map.h"

Map::Map() : territory(std::make_shared<Territory>()) {}

Map::Map(const Map& other)
{
    this->territory = other.territory;         
    this->cartographers = other.cartographers; 
    this->history.clear();
}

Map& Map::operator=(const Map& other)
{
    if (this != &other) {
        this->territory = other.territory;
        this->cartographers = other.cartographers;
        this->history.clear();
    }
    return *this;
}

bool Map::isLinked() const
{
    return territory.use_count() > 1;
}

long Map::useCount() const
{
    return territory.use_count();
}

void Map::unlink()
{
    if (isLinked()) {
        
        territory = std::make_shared<Territory>(*territory);
        history.clear(); 
    }
}

void Map::addCartographer(std::shared_ptr<Cartographer> c)
{
    if (c) {
        cartographers.push_back(c);
    }
}

void Map::execute(std::unique_ptr<Command> cmd)
{
    if (cmd) {
        cmd->execute();
        history.push_back(std::move(cmd));
    }
}

void Map::undo()
{
    if (!history.empty()) {
        history.back()->undo(); 
        history.pop_back();  
    }
    else {
        std::cout << "No commands to undo.\n";
    }
}

void Map::printHistory() const
{
    std::cout << "--- Command History ---\n";
    if (history.empty()) {
        std::cout << "  (no history)\n";
        return;
    }
    for (size_t i = 0; i < history.size(); ++i) {
        std::cout << i + 1 << ". " << history[i]->description() << "\n";
    }
}

void Map::print() const
{
    std::cout << "=== MAP INFORMATION ===\n";
    std::cout << "Linked Status: " << (isLinked() ? "Yes" : "No")
        << " (Shared by " << useCount() << " maps)\n";

    std::cout << "Cartographers involved:\n";
    if (cartographers.empty()) {
        std::cout << "  (none)\n";
    }
    else {
        for (const auto& c : cartographers) {
            std::cout << "  - ";
            c->print(); 
        }
    }

    territory->print();
    std::cout << "\n";
}

std::shared_ptr<Territory> Map::getTerritory()
{
    return territory;
}
