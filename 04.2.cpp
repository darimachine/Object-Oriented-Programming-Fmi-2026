
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

enum class Type {
	BLUEBERRY, QUEEN, MANGO, KIWI, RASPBERRY
};

class Narga {
private:
	double price;
	char brand[1024];
	Type type;

public

	Narga() : price(0), type(Type::MANGO) {
		brand[0] = '\0';
	}

	Narga(double price, const char* newBrand, Type newType) {
		this->price = price;
		strcpy(brand, newBrand);
		type = newType;
	}

	void setPrice(double newPrice) {
		price = newPrice;
	}

	void setBrand(const char* newBrand) {
		strcpy(brand, newBrand);
	}

	void setType(Type newType) {
		type = newType;
	}

	double getPrice() const {
		return price;
	}

	const char* getBrand() const {
		return brand;
	}

	Type getType() const {
		return type;
	}

	void read() {
		cin >> price;
		cin >> brand;

		int t;
		cin >> t;
		type = (Type)t;
	}

	void print() const {
		cout << "Price: " << price << endl;
		cout << "Brand: " << brand << endl;
		cout << "Type: " << (int)type << endl;
	}
};
