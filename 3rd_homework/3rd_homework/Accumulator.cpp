#include "Accumulator.h"
#include <iostream>

Accumulator::Accumulator(const std::string& inpMan, const std::string& inpDesc, unsigned inpCap, const std::string& BID) :
	CarPart(inpMan, inpDesc), capacity(inpCap), batteryID(BID)
{
}

void Accumulator::print(std::ostream& os) const
{
	CarPart::print(os);
	os << capacity << " Ah"<<'\n';
}
