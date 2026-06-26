#pragma once
#include <memory>
#include "Landmark.h"
class Dungeon : public Landmark
{
private:
    int depth;
public:
    Dungeon(const std::string& name, Coords coords, int threat, int depth);
    std::string getType() const override;
    void print() const override;
    std::unique_ptr<Landmark> clone() const override;
};

