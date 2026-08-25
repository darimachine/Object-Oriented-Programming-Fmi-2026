#pragma once
#include "Cartographer.h"

class ExpeditionLeader : public Cartographer
{
private:

	unsigned expediotionsCount = 0;

public:

	ExpeditionLeader() = default;
	ExpeditionLeader(std::string name, const unsigned yearsExperience, const unsigned expediotionsCount);

	[[nodiscard]] virtual std::string getRole() const override;
	virtual void print() const override;
};
