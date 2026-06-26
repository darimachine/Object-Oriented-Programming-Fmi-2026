#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Map.h"

class Curator {
	std::vector<std::unique_ptr<Map>> maps;

public:
    Curator() = default;
    Curator(const Curator&) = delete;//because of the unique pointer
    Curator& operator=(const Curator&) = delete;

    Map& addLinkedMap(const std::string& title, std::shared_ptr<Territory> territory);
    Map& addIndependentMap(const std::string& title, Territory territory);
    Map& copyAsIndependent(const std::string& sourceTitle, const std::string& newTitle);
    Map& getMap(const std::string& title);

    void listMaps() const;
};