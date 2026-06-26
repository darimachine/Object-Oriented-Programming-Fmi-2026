#include "Curator.h"
#include <stdexcept>
#include <iostream>

Map& Curator::addLinkedMap(const std::string& title, std::shared_ptr<Territory> territory)
{
    maps.push_back(std::make_unique<Map>(title, std::move(territory)));
    return *maps.back();
}

Map& Curator::addIndependentMap(const std::string& title, const Territory& territory)
{
    auto territoryCopy = std::make_shared<Territory>(territory);
    maps.push_back(std::make_unique<Map>(title, std::move(territoryCopy)));
    return *maps.back();
}

Map& Curator::copyAsIndependent(const std::string& sourceTitle, const std::string& newTitle)
{
    Map& source = getMap(sourceTitle);
    auto copy = std::make_unique<Map>(source);
    copy->unlink();
    copy->setTitle(newTitle);
    maps.push_back(std::move(copy));
    return *maps.back();
}

Map& Curator::getMap(const std::string& title)
{
    auto mapIterator = std::find_if(maps.begin(), maps.end(),
        [&title](const std::unique_ptr<Map>& map)
        {
            return map->getTitle() == title;
        });

    if (mapIterator == maps.end())
    {
        throw std::invalid_argument("Map not found: " + title);
    }

    return **mapIterator;
}

void Curator::listMaps() const
{
    std::cout << "Curator map list" << std::endl;
    for (const auto& map : maps)
    {
        std::cout << map->getTitle();
        std::cout << " | linked: ";
        if (map->isLinked())
        {
            std::cout << "yes";
        }
        else
        {
            std::cout << "no";
        }
        std::cout << " | territory use_count=" << map->useCount() << std::endl;
    }
}

