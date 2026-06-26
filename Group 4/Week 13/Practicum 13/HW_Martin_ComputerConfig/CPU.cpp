#include "CPU.h"

CPU::CPU(const std::string& ticket, unsigned short cores, unsigned short clockSpeed) : Component(ticket)
{
	if (cores < 1 || cores > 8)
	{
		throw std::invalid_argument("The cores are not in the boundaries (1,8).");
	}
	else
		this->cores = cores;

	if (clockSpeed <= 0)
	{
		throw std::invalid_argument("Clock speed is not in the correct format.");
	}
	else
		this->clockSpeed = clockSpeed;
}

std::unique_ptr<Component> CPU::clone() const
{
	return std::make_unique<CPU>(*this);
}

double CPU::price() const
{
	return cores * priceByCore;
}

void CPU::output(std::ostream& os) const
{
	os << "CPU, ticket: " << getTicket() << std::endl;
	os << "-------------------------" << "\n";
	os << " - price: " << price() << "\n";
	os << " - cores: " << cores << "\n";
	os << " - clockSpeed: " << clockSpeed << "\n";
}
