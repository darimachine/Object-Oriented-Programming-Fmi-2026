#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(const std::string& name, Coords coords, int threat, int depth) : Landmark(name, coords, threat), depth(depth)
{
}

std::string Dungeon::getType() const
{
	return "Dungeon";
}

void Dungeon::print() const
{
	std::cout << "Dungeon " << name << " (" << coords.x << ", " << coords.y << ")" << " | threat: " << threat << " | depth: " << depth << std::endl;
}

std::unique_ptr<Landmark> Dungeon::clone() const
{
	return std::make_unique<Dungeon>(*this);
}
