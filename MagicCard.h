#pragma once
#include<print>
#include"TypeConverter.h"

class MagicCard
{
private:
	char name[25];
	char effect[100];
	Type type;


public:
	MagicCard();

	MagicCard(const char* name, const char* effect, const char* type);

	static void describeType();

	void printInfo()const;
};

