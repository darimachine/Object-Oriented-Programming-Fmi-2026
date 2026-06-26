#pragma once
#include <string>
#include "Coordinates.h"
#include <stdexcept>

constexpr unsigned int MIN_THREAT = 0;
constexpr unsigned int MAX_THREAT = 10;

class Landmark
{
	protected:
		std::string name;
		Coordinates coords;
		unsigned int threat;

	public:
		Landmark(const std::string& inpName, const Coordinates& inpCoords, unsigned int inpThreat);
		virtual std::string getType() const = 0;;
		virtual void print() const = 0;
		virtual ~Landmark() = default;
		const std::string& getName() const;
};

