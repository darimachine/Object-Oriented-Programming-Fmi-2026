#pragma once
#include <iostream>
using namespace std;
class Recipient
{
	string name;
	string address;

public:
	Recipient(const string& name, const string& address);

	const string& getAddress() const;
	const string& getName() const;

	friend ostream& operator<<(ostream & os, const Recipient & r);
};

