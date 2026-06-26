#include "Dungeon.h"
#include <iostream>

Dungeon::Dungeon(const std::string& n, Coords c1, int t, int d) : Landmark(n, c1, t), depth(d) {}

std::unique_ptr<Landmark> Dungeon::clone() const
{
	return std::make_unique<Dungeon>(*this);
}

std::string Dungeon::getType() const
{
	return "dungeon";
}

void Dungeon::print() const
{
	std::cout << "(Dungeon) Name: " << name << ", Coords: (" << c.x << ", " << c.y << ")" << ", threat level: " << threat << ", depth: " << depth << "\n";
}
