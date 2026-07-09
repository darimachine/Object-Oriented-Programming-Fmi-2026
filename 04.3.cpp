
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

class Alchohol {
private:
	char name[128];
	double price;
public:
	Alchohol() {
		name[0] = '\0';
		price = 0;
	}
	Alchohol(const char* newName, double newPrice) {
		strcpy(name, newName);
		price = newPrice;
	}

	void setPrice(double newPrice) {
		price = newPrice;
	}

	void setName(const char* newName) {
		strcpy(name, newName);
	}
	double getPrice() const {
		return price;
	}

	const char* getName() const {
		return name;
	}
};
