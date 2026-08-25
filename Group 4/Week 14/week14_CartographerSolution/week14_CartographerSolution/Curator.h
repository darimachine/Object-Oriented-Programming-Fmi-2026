#pragma once
#include "Map.h"

class Curator
{
private:

	std::vector<std::unique_ptr<Map>> maps;

public:

	const Map& addLinkedMap(std::string title, std::shared_ptr<Territory> territory);
	const Map& addIndependentMap(std::string title, Territory& territory);
	Map& copyAsIndependent(std::string sourceTitle, std::string newTitle);
	const Map& getMap(const std::string& title) const;
	void listMaps() const;
};

