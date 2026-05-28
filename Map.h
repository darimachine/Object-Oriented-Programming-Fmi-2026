#pragma once
#include <vector>
#include <memory>
#include "Territory.h"
#include "Cartographer.h"
#include "Command.h"

class Map {
private:
    std::shared_ptr<Territory> territory;
    std::vector<std::shared_ptr<Cartographer>> cartographers;
    std::vector<std::unique_ptr<Command>> history;

public:
    Map();

    Map(const Map& other);

    Map& operator=(const Map& other);

    ~Map() = default;

    bool isLinked() const;
    long useCount() const;
    void unlink();

    void addCartographer(std::shared_ptr<Cartographer> c);
    void execute(std::unique_ptr<Command> cmd);
    void undo();

    void printHistory() const;
    void print() const;

    std::shared_ptr<Territory> getTerritory();
};
