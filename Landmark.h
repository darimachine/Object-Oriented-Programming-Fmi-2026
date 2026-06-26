#pragma once
#include <iostream>

struct Coords {
	double x;
	double y;
};

class Landmark {
protected:
	std::string name = "";
	Coords c;
	int threat;
	
public:
	std::string getName() const;
	virtual std::string getType() const = 0;
	virtual void print() const = 0;
	Landmark(const std::string& n, Coords c1, int t);
	virtual ~Landmark() = default;
	virtual std::unique_ptr<Landmark> clone() const = 0;
};