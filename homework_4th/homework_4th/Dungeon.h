#pragma once
#include "Landmark.h"
class Dungeon : public Landmark
{
	private:
		unsigned int depth;

	public:
		Dungeon(const std::string& inpName, const Coordinates& inpCoords,
			unsigned int inpThreat, unsigned int inpDepth);

		std::string getType() const override;
		void print() const override;
};

