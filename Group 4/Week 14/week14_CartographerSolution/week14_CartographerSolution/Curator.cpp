#include "Curator.h"


const Map& Curator::addLinkedMap(std::string title, std::shared_ptr<Territory> territory)
{

    auto temp = std::make_unique<Map>(Map(std::move(title), territory));
 
    Map& currentMap = *temp;

    maps.push_back(std::move(temp));
    
    return currentMap;
}

const Map& Curator::addIndependentMap(std::string title, Territory& territory)
{
    auto temp = std::make_unique<Map>(Map(std::move(title), std::move(territory)));

    Map& currentMap = *temp;

    maps.push_back(std::move(temp));

    return currentMap;
}

Map& Curator::copyAsIndependent(std::string sourceTitle, std::string newTitle)
{
    const unsigned size = maps.size();

    for (unsigned i = 0; i < size; i++)
    {
        if (maps[i]->getTitle() == sourceTitle)
        {
            Map independent = Map(*(maps[i]));
            Map& temp = independent;

            maps.push_back(std::make_unique<Map>(std::move(independent)));

            return temp;
        }
    }

    throw std::invalid_argument("No map with such title exists");
}

const Map& Curator::getMap(const std::string& title) const
{
    const unsigned size = maps.size();

    for (unsigned i = 0; i < size; i++)
    {
        if (maps[i]->getTitle() == title)
        {
            Map* map = maps[i].get();
            Map& temp = *map;
            return temp;
        }
    }

    throw std::invalid_argument("No map with such title exists");
}

void Curator::listMaps() const
{
    const unsigned size = maps.size();

    for (unsigned i = 0; i < size; i++)
    {
        maps[i]->print();
    }
}
