#include "Engine.h"
#include <stdexcept>
#include <iostream>
void Engine::setHP(int inpHP)
{
	if (inpHP < MIN_HORSE_POWERS)
	{
		throw std::invalid_argument("The inputed horsepowers are below minimum");
	}
	horsePowers = inpHP;
}

Engine::Engine(const std::string& inpMan, const std::string& inpDesc, int inpHP) : CarPart(inpMan, inpDesc)
{
	setHP(inpHP);	
}

void Engine::print(std::ostream& os) const
{
	CarPart::print(os);
	os << horsePowers << " hp" << '\n';
}
