#pragma once
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Command.h"
#include "MyException.h"
class Landmark;
class Territory;
class Cartographer;

class Map
{
	std::shared_ptr<Territory> t;
	std::vector<std::shared_ptr<Cartographer>> workers;
	std::vector<std::unique_ptr<Command>> history;
public:
	Map() = default;
	std::shared_ptr<Map> unlink();
	void addCartographer(std::shared_ptr<Cartographer> c);
	void execute(std::unique_ptr<Command> c);// -изпълнява командата и я добавя в историята
	void undo();// -отменя последната команда
	void printHistory() const;
	std::shared_ptr<Territory>& getTerritory();
	bool isLinked();
	int useCount();



};

