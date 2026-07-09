#pragma once
#include"Vehicle.h"

class VehicleList
{
private:
	static constexpr size_t DEFAULT_CAPACITY = 16;
	Vehicle** vehicles{ nullptr };
	size_t countOfVehicles = 0;
	size_t capacity = DEFAULT_CAPACITY;

	void copyFrom(const VehicleList& other);
	void moveFrom(VehicleList&& other);
	void free();
	void resize(size_t newCap);
	bool isRepeat(const char* regNum);

public:
	explicit VehicleList(size_t capacity);

	VehicleList(const VehicleList&);
	VehicleList& operator=(const VehicleList&);

	VehicleList(VehicleList&&) noexcept;
	VehicleList& operator=(VehicleList&&) noexcept;
	~VehicleList();


	VehicleList& operator+=(const Vehicle&);
	VehicleList& operator-=(const Registration& regNum);

	Vehicle& operator[](size_t index);
	const Vehicle& operator[](size_t index)const;

	size_t operator()(const char* code)const;
	explicit operator bool()const;

	size_t getFirstFreeSlot()const;
	size_t getFirstTakenSlot()const;
	size_t size()const;
	size_t getCapacity()const;
	const Vehicle* const* getList()const;

	bool isFreeSlot(size_t pos)const;
	bool isEmpty()const;

	Vehicle* find(const Registration& regNum)const;

	friend std::ostream& operator<<(std::ostream& os, const VehicleList& v);
};

std::strong_ordering operator<=>(const VehicleList& lhs, const VehicleList& rhs);
bool operator==(const VehicleList& lhs, const VehicleList& rhs);