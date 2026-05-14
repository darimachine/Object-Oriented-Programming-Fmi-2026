#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Alchohol.h"

Alchohol::Alchohol() : price(0.0)
{
	name[0] = '\0';
}

Alchohol::Alchohol(const char* name, double price) : price(price) 
{
    strncpy(this->name, name, 128);
    this->name[128] = '\0';
}

const char* Alchohol::getName() const
{
    return name;
}

double Alchohol::getPrice() const 
{ 
    return price; 
}

void Alchohol::setName(const char* name)
{
    strncpy(this->name, name, 128);
    this->name[128] = '\0';
}

void Alchohol::setPrice(double price)
{
    this->price = price;
}