#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "Merchant.h"
using namespace std;
class MarketPlace
{
	Merchant** merchants = nullptr;
	unsigned int size = 0;
	unsigned int capacity;
	char* description = nullptr;
	double slotRent;

	void free();
	void copyFrom(const MarketPlace& other);
	void moveFrom(MarketPlace&& other) noexcept;

public:
	MarketPlace(const char* description, unsigned int capacity, double slotRent);

	MarketPlace(const MarketPlace& other);
	MarketPlace& operator=(const MarketPlace& other);

	MarketPlace(MarketPlace&& other) noexcept;
	MarketPlace& operator=(MarketPlace&& other) noexcept;

	~MarketPlace();

	MarketPlace& operator+=(const Merchant& m);

	MarketPlace& operator-=(double minRevenue);

	friend ostream& operator<<(ostream& os, const MarketPlace& m);

	partial_ordering operator<=>(const MarketPlace& other) const;

	MarketPlace& operator()(int days);

	explicit operator bool() const;

	void addAt(int pos, const Merchant& m);

	bool isFreeSlot(int pos) const;

	unsigned int takenSlots() const;

	double getProfit() const;

	double averageProfit() const;
};

