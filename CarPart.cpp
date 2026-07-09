#include "CarPart.h"

unsigned CarPart::nextId = 0;

CarPart::CarPart(const string& producer,const string& description):
	id(++nextId),producer(producer),description(description){ }

ostream& operator<<(ostream& os, const CarPart& cp)
{
	return os << "(" << cp.id << ") by "
		<< cp.producer << " - " << cp.description << '\n';
}