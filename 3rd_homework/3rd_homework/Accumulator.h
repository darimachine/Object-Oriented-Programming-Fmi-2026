#pragma once
#include "CarPart.h"
class Accumulator : public CarPart
{
	private:
		unsigned capacity;
		std::string batteryID;

	public:
		Accumulator(const std::string& inpMan, const std::string& inpDesc, unsigned inpCap, const std::string& inpBID);
		void print(std::ostream& os) const override
};

