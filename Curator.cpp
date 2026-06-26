#include "Curator.h"
#include<stdexcept>
#include<iostream>

Map& Curator::addLinkedMap(const string& title, shared_ptr<Territory> territory)
{
    maps.emplace_back(title, territory);
    return *maps.back();
}

Map& Curator::addIndependentMap(const string& title, Territory territory)
{
    maps.emplace_back(title, territory);
    return *maps.back();
}

Map& Curator::copyAsIndependent(const string& sourceTitle, const string& newTitle)
{
    auto it = find_if(maps.begin(), maps.end(), [&sourceTitle]
    (const unique_ptr<Map>& map)
        {
            return map->getTitle() == sourceTitle;
        });

    if (it == maps.end())
    {
        throw invalid_argument("Map not found.");
    }

    Map copy = *(it->get());
    copy.unlink();
    copy.setTitle(newTitle);

    maps.push_back(make_unique<Map>(copy));
    return *maps.back();
}

Map& Curator::getMap(const string& title) const
{
    auto it = find_if(maps.begin(), maps.end(), [&title](const unique_ptr<Map>& m)
        {
            return m->getTitle() == title;
        });

    if (it == maps.end())
    {
        throw invalid_argument("Map not found");
    }

    return *(it->get());
}

void Curator::listMaps() const
{
    cout << "Maps:" << '\n';
    for (const auto& map : maps)
    {
        map->print();
    }
}
