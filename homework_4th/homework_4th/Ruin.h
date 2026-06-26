#pragma once
#include "Landmark.h"
#include <string>
class Ruin : public Landmark
{
	private:
		std::string civilization;

	public:
		Ruin(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat,
			const std::string inpCivilization);

		std::string getType() const override;
		void print() const override;
};

