#pragma once
#include "Territory.h"
#include "Cartographer.h"
#include "Command.h"

#include <stack>

class Map
{

private:

	std::string title;
	std::shared_ptr<Territory> territory;
	std::vector<std::shared_ptr<Cartographer>> cartograhers;
	std::vector<std::unique_ptr<Command>> commandHistory;

public:

	Map() = default;
	Map(std::string title, Territory&& territory);
	Map(std::string title, std::shared_ptr<Territory> territory);

	Map(const Map& other);
	Map& operator=(const Map& other);

	Map(Map&& other) noexcept = default;
	Map& operator=(Map&& other) noexcept = default;

	std::unique_ptr<Map> unlink() const;
	void addCartographer(std::shared_ptr<Cartographer> cartographer);
	void execute(std::unique_ptr<Command> command);
	void undo();
	void printHistory() const;
	std::shared_ptr<Territory> getTerritory() const;
	bool isLinked() const;
	unsigned useCount() const;
	void print() const;

	const std::string& getTitle() const;

	~Map() = default;
};

