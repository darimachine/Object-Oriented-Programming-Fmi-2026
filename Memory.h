#pragma once
#include"Component.h"

class Memory:public Component
{
private:
	static constexpr double MEMORY_PRICE = 49.99;
	unsigned short capacity;

public:
	Memory(const string& label, unsigned short capacity);

	double price()const override;
	void output(std::ostream& os)const override;

	unique_ptr<Component> clone()const override;
};

