#pragma once
#include <vector>
#include <memory>
#include "Map.h"
class Curator
{
    std::vector<std::unique_ptr<Map>> maps;
public:
    Map& addLinkedMap(const std::string& title, std::shared_ptr<Territory> territory);
    Map& addIndependentMap(const std::string& title, const Territory& territory);
    Map& copyAsIndependent(const std::string& sourceTitle, const std::string& newTitle);
    Map& getMap(const std::string& title);
    void listMaps() const;
};

