#pragma once

#include "Territory.h"
#include "Cartographer.h"
#include "Command.h"
#include <memory>
#include <vector>
#include <iostream>
#include <memory>
class Map
{
	private:
		std::string title;
		std::shared_ptr<Territory> territory;
		std::vector<std::shared_ptr<Cartographer>> cartographers;
		std::vector<std::unique_ptr<Command>> history;

	public:
		Map(std::shared_ptr<Territory> initialTerritory);
		Map(const Map& other);
		Map& operator = (const Map & other) = delete;

		void unlink();
		void addCartographer(std::shared_ptr<Cartographer> joiningCart);
		void execute(std::unique_ptr<Command> command);
		void undo();
		void printHistory() const;

		bool isLinked() const;
		long useCount() const;
		Territory& getTerritory() const;
		void print() const;
			 
		const std::string& getTitle() const;
};

