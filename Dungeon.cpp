#include "Dungeon.h"

Dungeon::Dungeon(const std::string& name, const Coords& coords, int threat, int depth)
:Landmark(name, coords, threat), depth(depth)
{}

std::string Dungeon::getType() const
{
	return "Dungeon";
}

void Dungeon::print() const
{
	Landmark::print();
	std::cout << " | Depth: " << depth << " floors\n";
}
