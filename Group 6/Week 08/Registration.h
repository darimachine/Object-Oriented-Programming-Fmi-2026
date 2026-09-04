#pragma once
#include<iostream>

class Registration {
	char reg[9];

public:
	bool isLetter(char c);
	bool isRegValid(const char* regNum);

	Registration(const char* regNum);
	Registration() = delete;

	friend std::ostream& operator<<(std::ostream& os, const Registration& r);
	auto operator<=>(const Registration& other) const;
	bool operator==(const Registration& other) const;

	const char* getReg() const;
};

class Vehicle {
	Registration reg;
	char* description;
	int year;
	int power;

public:
	Vehicle() = delete;
	//rule of five
	Vehicle(const Registration& regN, const char* _description, int _year, int _power);
	Vehicle(const Vehicle& other);
	Vehicle& operator=(const Vehicle& other);
	Vehicle(Vehicle&& other) noexcept;
	Vehicle& operator=(Vehicle&& other) noexcept;
	~Vehicle();

	friend std::ostream& operator<<(std::ostream& os, const Vehicle& v);
	auto operator<=>(const Vehicle& other) const;
	bool operator==(const Vehicle& other) const;

	void copyFrom(const Vehicle& other);
	void free();

	const Registration& getRegNum() const;
};

class VehicleList {
	Vehicle** listVehicle = nullptr;
	int cap;
	int vCount;

	void resize();

public:

	VehicleList(int _cap);

	VehicleList(const VehicleList& other);
	VehicleList& operator=(const VehicleList& other);
	VehicleList(VehicleList&& other) noexcept;
	VehicleList& operator=(VehicleList&& other) noexcept;
	~VehicleList();

	VehicleList& operator+=(const Vehicle& v);
	VehicleList& operator-=(const Registration& reg);
	int operator()(const char* townCode) const;
	explicit operator bool() const;
	friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
	auto operator<=>(const VehicleList& other) const;
	bool operator==(const VehicleList& other) const;
	Vehicle* operator[](int index);
	const Vehicle* operator[](int index) const;

	bool isFreeSlot(int pos) const;
	bool isEmpty() const;
	Vehicle* find(const Registration& reg) const;
	int size() const;
	int capacity() const;

	void free();
	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other);
};