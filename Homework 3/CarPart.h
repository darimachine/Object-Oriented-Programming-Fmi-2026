#pragma once
#include <iostream>
class CarPart
{
protected:
	static unsigned int num;
	int id;
	std::string name;
	std::string descr;
public: 
	CarPart(std::string _name, std::string _descr);
	std::ostream& operator << (const CarPart& part);
	virtual void print(std::ostream& os) const;
};

class Tires : public CarPart {
protected:
	int width;
	int profile;
	int diameter;
public: 
	Tires(std::string _name, std::string _descr, int _width, int _profile, int _diameter);
	void print(std::ostream& os) const override;
};

class Accumulator : public CarPart {
protected:
	int capacity;
	std::string batteryId;
public:
	Accumulator(std::string _name, std::string _descr, int _capacity, std::string _batteryId);
	void print(std::ostream& os) const override;
};

class Engine : public CarPart {
protected:
	int horsePower;
public:
	Engine(std::string _name, std::string _descr, int _horsePower);
	void print(std::ostream& os) const override;

};
