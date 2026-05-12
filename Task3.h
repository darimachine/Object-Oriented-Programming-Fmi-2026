#pragma once
#include <string>
#include <iostream>

class CarPart {
protected:
	unsigned int id;
	std::string manifacturer;
	std::string description;
	
	virtual void print(std::ostream&) const;

public:
	CarPart(unsigned int, std::string&, std::string&);
	friend std::ostream& operator<<(std::ostream&, const CarPart&);
	virtual ~CarPart() = default;
};

class Engine :public CarPart {
	unsigned int horsePower;

protected:
	void print(std::ostream&) const override;
public:
	Engine(unsigned int, std::string&, std::string&, unsigned int);

};

class Tyre : public CarPart {
	unsigned int width, profile, diameter;

	static void validateParameters(unsigned, unsigned, unsigned);
protected:
	void print(std::ostream&) const override;
public:
	Tyre(unsigned int, std::string&, std::string&, unsigned int, unsigned int, unsigned int);
};

class Accumulator : public CarPart {
	unsigned int capacity;
	std::string batteryId;

protected:
	void print(std::ostream&) const override;
public:
	Accumulator(unsigned int, std::string&, std::string&, unsigned int, std::string&);
};