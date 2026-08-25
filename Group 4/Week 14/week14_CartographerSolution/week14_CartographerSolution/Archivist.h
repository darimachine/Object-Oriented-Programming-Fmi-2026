#pragma once
#include "Cartographer.h"

class Archivist : public Cartographer
{
private:

	std::string institution;

public:

	Archivist() = default;
	Archivist(std::string name, const unsigned yearsExperience, std::string institution);

	[[nodiscard]] virtual std::string getRole() const override;
	virtual void print() const override;
};

