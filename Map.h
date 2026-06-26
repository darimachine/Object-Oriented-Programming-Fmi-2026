#pragma once
#include"Territory.h"
#include"Cartographer.h"
#include"Command.h"

class Map
{
private:
	string title;
	shared_ptr<Territory> territory;
	vector<shared_ptr<Cartographer>> cartographers;
	vector<unique_ptr<Command>> history;

public:
	Map() = default;
	Map(const string& title, Territory territory);
	Map(const string& title, shared_ptr<Territory> territory);

	Map(const Map& other);
	Map& operator=(const Map& other);
	Map(Map&&) noexcept = default;
	Map& operator=(Map&&) noexcept = default;

	const string& getTitle()const;
	void setTitle(const string& newTitle);

	bool isLinked()const;
	void unlink();
	void addCartographer(shared_ptr<Cartographer> c);
	void execute(unique_ptr<Command> command);
	void undo();
	void printHistory()const;
	size_t useCount()const;
	shared_ptr<Territory> getTerritory()const;
	void print();
};

