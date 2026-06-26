#include "Dungeon.h"
#include <print>
Dungeon::Dungeon(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat, 
	unsigned int inpDepth) : Landmark(inpName, inpCoords, inpThreat), depth(inpDepth)
{
}

std::string Dungeon::getType() const
{
	return "Dungeon";
}

void Dungeon::print() const
{
	Landmark::print();
	std::println("depth: {}, type: {}", depth, getType());
}
