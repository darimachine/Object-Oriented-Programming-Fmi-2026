#pragma once
#include <iostream>
#include <string>

class CarPart {
protected:
	static unsigned counter;
	unsigned id;
	std::string manufacturer = "";
	std::string description = "";

public:

	CarPart(std::string _manufacturer, std::string _description);

	virtual void print(std::ostream& os) const;
	friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
};


class Tire : public CarPart{

	int width;
	int profile;
	int rimSize;

public:

	Tire(const std::string& _manufacturer, const std::string& _description, int _width, int _profile, int _rimSize);
	void print(std::ostream& os) const override;
};

class Engine : public CarPart {

	int horsePower;

public:

	Engine(const std::string& _manufacturer, const std::string& _description, int _horsepower);
	void print(std::ostream& os) const override;
};

class Battery : public CarPart {

	int ampHours;
	std::string batteryId = "";

public:

	Battery(const std::string& _manufacturer, const std::string& _description, int _ampHours, const std::string& _batteryId);
	void print(std::ostream& os) const override;

};