#pragma once
#include"Component.h"

class CPU:public Component
{
private:
	unsigned short cores;
	unsigned short clockSpeed;

public:
	CPU(const string& label,unsigned short cores, unsigned short clockSpeed);

	double price()const override;
	void output(ostream& os)const override;

	unique_ptr<Component> clone()const override;
};

