#pragma once
#include<string>
#include<fstream>
using namespace std;

class Component
{
private:
	string label;
	
public:
	Component(const string& label);

	Component(const Component& other) = delete;
	Component& operator=(const Component& other) = delete;

	virtual double price()const = 0;
	virtual void output(ostream& os)const = 0;

	virtual ~Component() = default;

	const string& getLabel()const;

	virtual unique_ptr<Component> clone()const = 0;
};

