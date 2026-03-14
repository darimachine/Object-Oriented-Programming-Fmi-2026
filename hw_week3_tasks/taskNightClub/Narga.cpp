#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Narga.h"

Narga::Narga() : price(0.0), taste(Taste::QUEEN) 
{
	brand[0] = '\0'; 
}

Narga::Narga(double price, const char* brand, Taste taste) : price(price), taste(taste)
{
	strncpy(this->brand, brand, 1024);
	this->brand[1024] = '\0';
	this->price = price;
	this->taste = taste;
}

double Narga::getPrice() const
{
	return price;
}

const char* Narga::getBrand() const
{
	return brand;
}

Taste Narga::getTaste() const
{
	return taste;
}

void Narga::setPrice(double price)
{
	this->price = price;
}

void Narga::setBrand(const char* brand)
{
	strncpy(this->brand, brand, 1024);
	this->brand[1024] = '\0';
}

void Narga::setTaste(Taste taste)
{
	this->taste = taste;
}

void Narga::readFromInput()
{
	char brand[1024];
	double price;
	char taste[32];

	std::cout << "Brand: ";
	std::cin.getline(brand, 1024);

	std::cout << "Price: ";
	std::cin >> price;

	std::cout << "Taste";
	std::cin >> taste;
}
void Narga::print() const 
{
	std::cout << "Brand: " << brand
		<< " Price: " << price
		<< " Taste: " << tasteToString(taste)
		<< std::endl;
}

Taste Narga::tasteFromString(const char* string)
{
	if (strcmp(string, "blueberry") == 0)
	{
		return Taste::BLUEBERRY;
	}
	if (strcmp(string, "queen") == 0)
	{
		return Taste::QUEEN;
	}
	if (strcmp(string, "mango") == 0)
	{
		return Taste::MANGO;
	}
	if (strcmp(string, "peach") == 0)
	{
		return Taste::PEACH;
	}
	if (strcmp(string, "strawberry") == 0)
	{
		return Taste::STRAWBERRY;
	}
	else
	{
		std::cout << "Unknown narga taste";
	}
	return Taste::QUEEN;
}

const char* Narga::tasteToString(Taste taste)
{
	switch (taste)
	{
	case Taste::BLUEBERRY:
		return "blueberry";
	case Taste::QUEEN:
		return "queen";
	case Taste::MANGO:
		return "mango";
	case Taste::PEACH:
		return "peach";
	case Taste::STRAWBERRY:
		return "strawberry";
	default:
		return "unknown";
	}
}
