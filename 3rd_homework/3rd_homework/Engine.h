#pragma once
#include "CarPart.h"

constexpr int MIN_HORSE_POWERS = 50;

class Engine : public CarPart
{
	private:
		int horsePowers;

		void setHP(int inpHP);

	public:
		Engine(const std::string& inpMan, const std::string& inpDesc, int inpHP);
		void print(std::ostream& os) const override;
};

