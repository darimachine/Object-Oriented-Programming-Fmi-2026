#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <compare>
using namespace std;
class Merchant
{
	static constexpr unsigned int MAX_SIZE = 1024;
	unsigned int id = 0;

	char name[MAX_SIZE];
	double income;

	static int idCount;

	double dailyRate;
public:

	Merchant(const char* name, double income, double dailyRate);

	friend ostream& operator<<(ostream&, const Merchant& merchant);

	auto operator<=>(const Merchant& other) const;
	
	double getIncome() const;
	double getId() const;

	Merchant& operator++();
	Merchant operator++(int dummy);

	

};

