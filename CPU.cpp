#include "CPU.h"
#include<stdexcept>
#include"CoresException.h"

CPU::CPU(const string& label,unsigned short cores, unsigned short clockSpeed) :
	Component(label),clockSpeed(clockSpeed)
{
	if (cores < 1 || cores>8)
	{
		throw CoresException(label);
	}
	this->cores = cores;
}

double CPU::price()const
{
	return cores * 19.99;
}

void CPU::output(ostream& os)const
{
	os << getLabel() << " " << cores << " " << clockSpeed << '\n';
}

unique_ptr<Component> CPU::clone()const
{
	return make_unique<CPU>(getLabel(), cores, clockSpeed);
}