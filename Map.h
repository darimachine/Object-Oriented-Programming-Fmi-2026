#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Territory.h"
#include "Cartographer.h"
#include "Command.h"

class Map {

        std::string title;
        std::shared_ptr<Territory> territory;
        std::vector<std::shared_ptr<Cartographer>> cartographers;
        std::vector<std::unique_ptr<Command>> history;

    public:
        Map(const std::string& _title, std::shared_ptr<Territory> _territory);
        Map(const Map& other);

        void unlink();
        void addCartographer(const std::shared_ptr<Cartographer> c);
        void execute(std::unique_ptr<Command> com);
        void undo();

        void printHistory() const;
        Territory& getTerritory();
        const Territory& getTerritory() const;
        bool isLinked() const;
        long useCount() const;
        void print() const;

        std::string getTitle() const;
        void setTitle(const std::string& newTitle);
};