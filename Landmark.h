#pragma once
#include <string>
#include <iostream>
#include "Additional.h"



class Landmark {
	std::string name;
	Coords coords;
	int threat;

	public:
		Landmark(const std::string& name, const Coords& coords, int threat);
		virtual ~Landmark() = default;

	virtual std::string getType() const = 0;
	virtual std::unique_ptr<Landmark> clone() const = 0;
	virtual std::string getName() const;
	virtual void print() const;
};
