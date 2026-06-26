#pragma once
#include"Map.h"

class Curator
{
private:
	vector<unique_ptr<Map>> maps;

public:
	Curator() = default;

	Map& addLinkedMap(const string& title, shared_ptr<Territory> territory);
	Map& addIndependentMap(const string& title, Territory territory);
    Map& copyAsIndependent(const string& sourceTitle, const string& newTitle);
	Map& getMap(const string& title)const;
	void listMaps()const;
};

