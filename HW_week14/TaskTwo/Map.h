#pragma once
#include <string>
#include <memory>
#include "Territory.h"
#include "Cartographer.h"
#include "Command.h"
class Map
{
    std::string title;
    std::shared_ptr<Territory> territory;
    std::vector<std::shared_ptr<Cartographer>> cartographers;
    std::vector<std::unique_ptr<Command>> history;
public:
    Map(const std::string& title, std::shared_ptr<Territory> territory);
    Map(const Map& other);
    Map& operator=(const Map& other);
    Map(Map&&) = default;
    Map& operator=(Map&&) = default;
    void unlink();
    void addCartographer(std::shared_ptr<Cartographer> cartographer);
    void execute(std::unique_ptr<Command> command);
    void undo();
    void printHistory() const;
    void print() const;
    Territory& getTerritory();
    const Territory& getTerritory() const;
    bool isLinked() const;
    long useCount() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);
    const std::vector<std::shared_ptr<Cartographer>>& getCartographers() const;
};

