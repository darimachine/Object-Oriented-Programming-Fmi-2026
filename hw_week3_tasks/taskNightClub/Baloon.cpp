#define _CRT_SECURE_NO_WARNINGS
#include "Baloon.h"
#include <iostream>
#include <string.h>

Baloon::Baloon() : price(0.0), color(BalloonColor::WHITE)
{

}

Baloon::Baloon(double price, BalloonColor color) : price(price), color(color)
{

}

double Baloon::getPrice() const
{
	return price;
}

BalloonColor Baloon::getColor() const
{
	return color;
}

void Baloon::setPrice(double price)
{
	this->price = price;
}

void Baloon::setColor(BalloonColor color)
{
	this->color = color;
}

BalloonColor Baloon::colorFromString(const char* string)
{
	if (strcmp(string, "white") == 0)
	{
		return BalloonColor::WHITE;
	}
	if (strcmp(string, "green") == 0)
	{
		return BalloonColor::GREEN;
	}
	if (strcmp(string, "red") == 0)
	{
		return BalloonColor::RED;
	}
	else
	{
		std::cout << "Unknown balloon color";
	}
	return BalloonColor::WHITE;
}

const char* Baloon::colorToString(BalloonColor color)
{
	switch (color)
	{
	case BalloonColor::WHITE: 
		return "white";
	case BalloonColor::GREEN: 
		return "green";
	case BalloonColor::RED:   
		return "red";
	default:                  
		return "unknown";
	}
}

