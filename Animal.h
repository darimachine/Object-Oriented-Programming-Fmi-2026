#pragma once
#include<string>
using namespace std;

class Animal
{
private:
	string name;
	unsigned age;
	string type;

public:
	Animal() = default;
	Animal(const string& name, unsigned age, const string& type);
};

