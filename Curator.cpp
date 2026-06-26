#include "Curator.h"

Map& Curator::addLinkedMap(const std::string& title, std::shared_ptr<Territory> territory)
{
    auto newMap = std::make_unique<Map>(title, territory);

    Map& RefMap = *newMap;
    maps.push_back(std::move(newMap));

    return RefMap;
}

Map& Curator::addIndependentMap(const std::string& title, Territory territory)
{
    auto indepTerritory = std::make_shared<Territory>(territory);
    auto newMap = std::make_unique<Map>(title, indepTerritory);
    Map& RefMap = *newMap;
    maps.push_back(std::move(newMap));

    return RefMap;
}

Map& Curator::copyAsIndependent(const std::string& sourceTitle, const std::string& newTitle)
{
    Map& sourceMap = getMap(sourceTitle);
    auto indepMap = std::make_unique<Map>(sourceMap);
    indepMap->setTitle(newTitle);
    indepMap->unlink();
    Map& RefMap = *indepMap;
    maps.push_back(std::move(indepMap));
    return RefMap;
}

Map& Curator::getMap(const std::string& title)
{
    for (const auto& mapPtr : maps)
    {
        if (mapPtr->getTitle() == title) {
            return *mapPtr;
        }
    }
    throw std::invalid_argument("Map not found!");
}

void Curator::listMaps() const
{
    std::cout << "Curator map collection (" << maps.size() << ")\n";

    if (maps.empty())
    {
        std::cout << "[The collection is empty]\n";
        return;
    }

    for (const auto& mapPtr : maps) {
        std::cout << "Title: " << mapPtr->getTitle() << "\n"
            << "Territory link count: " << mapPtr->useCount() << "\n";
    }
}
