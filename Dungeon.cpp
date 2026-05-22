#include "Dungeon.h"
#include<stdexcept>
#include<print>

Dungeon::Dungeon(const string& name, Coordinates coords, unsigned threat, int depth):
    Landmark(name,coords,threat)
{
    if (depth < 0)
    {
        throw invalid_argument("The depth cannot be a negative number");
    }
    this->depth = depth;
}

string Dungeon::getType() const
{
    return "Dungeon";
}

void Dungeon::print() const
{
    println("Name: {}, Coordinates: {} {}, Threat: {}, Depth: {}",
        getName(), getCoords().x, getCoords().y, getThreat(), depth);
}

int Dungeon::getDepth() const
{
    return depth;
}
