#define _CRT_SECURE_NO_WARNINGS
#include "Nightclub.h"
#include "Alchohol.h"
#include "Baloon.h"
#include "Narga.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>

int Nightclub::findBaloon(BalloonColor color) const
{
	for (int i = 0; i < baloonSize; ++i)
	{
		if (baloons[i].getColor() == color)
		{
			return i;
		}
	}
	return -1;
}

int Nightclub::findAlchohol(const char* name) const
{
	for (int i = 0; i < alchoholSize; ++i)
	{
		if (strcmp(alchohols[i].getName(), name) == 0)
		{
			return i;
		}
	}
	return -1;
}

int Nightclub::findNarga(const char* brand, Taste taste) const
{
	for (int i = 0; i < nargaSize; ++i)
	{
		if (strcmp(nargas[i].getBrand(), brand) == 0 && nargas[i].getTaste() == taste)
		{
			return i;
		}
	}
	return -1;
}

int Nightclub::splitLine(const char* line, char tokens[][1025], int maxToken)
{
	int tokenCount = 0;
	const char* currPos = line;
	while (*currPos != '\0' && tokenCount < maxToken)
	{
		const char* dashPos = strchr(currPos, '-');
		int tokenLen;
		if (dashPos != nullptr)
		{
			tokenLen = dashPos - currPos;
		}
		else
		{
			tokenLen = strlen(currPos);
		}
		if (tokenLen > 1024)
		{
			tokenLen = 1024;
		}
		strncpy(tokens[tokenCount], currPos, tokenLen);
		tokens[tokenCount][tokenLen] = '\0';
		trimInPlace(tokens[tokenCount]);
		tokenCount++;
		if (dashPos == nullptr)
		{
			break;
		}
		currPos = dashPos + 1;
	}
	return tokenCount;
}

void Nightclub::trimInPlace(char* string)
{
	int start = 0;
	while (string[start] == ' ')
	{
		start++;
	}
	int i = 0;
	while (string[start] != '\0')
	{
		string[i] = string[start];
		i++;
		start++;
	}
	string[i] = '\0';
	int end = i - 1;
	while (end >= 0 && string[end] == ' ')
	{
		string[end] = '\0';
		end--;
	}
}

Nightclub::Nightclub() : baloonSize(0), alchoholSize(0), nargaSize(0)
{
	for (int i = 0; i < (int)BalloonColor::COUNT; i++)
	{
		baloonCounts[i] = 0;
	}

	for (int i = 0; i < 512; i++)
	{
		alchoholCounts[i] = 0;
	}

	for (int i = 0; i < (int)Taste::COUNT; i++)
	{
		nargaCounts[i] = 0;
	}
}

double stringToDouble(const char* string)
{
	double result = 0.0;
	int i = 0;
	bool negative = false;
	if (string[0] == '-')
	{
		negative = true;
		i++;
	}
	while (string[i] && string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] == '.')
	{
		i++;
		double frac = 0.0;
		double divisor = 10.0;
		while (string[i] && string[i] >= '0' && string[i] <= '9')
		{
			frac += (string[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
		result += frac;
	}
	if (negative)
	{
		return -result;
	}
	return result;
}

void Nightclub::addBaloonFromLine(const char* line)
{
	char tokens[2][1025];

	int tokenCount = splitLine(line, tokens, 2);

	if (tokenCount < 2)
	{
		std::cout << "Bad balloon line" << std::endl;
		return;
	}
	BalloonColor color = Baloon::colorFromString(tokens[0]);
	double price = stringToDouble(tokens[1]);
	int index = findBaloon(color);
	if (index != -1)
	{
		baloonCounts[index]++;
		return;
	}
	if (baloonSize >= 1024)
	{
		std::cout << "Balloon capacity full" << std::endl;
		return;
	}
	baloons[baloonSize] = Baloon(price, color);
	baloonCounts[baloonSize] = 1;
	baloonSize++;
}

void Nightclub::addNargaFromLine(const char* line)
{
	char tokens[3][1025];
	int tokenCount = splitLine(line, tokens, 3);
	if (tokenCount < 3)
	{
		std::cout << "Bad narga line" << std::endl;
		return;
	}
	const char* brand = tokens[0];
	Taste taste = Narga::tasteFromString(tokens[1]);
	double price = stringToDouble(tokens[2]);
	int index = findNarga(brand, taste);
	if (index != -1)
	{
		nargaCounts[index]++;
		return;
	}
	if (nargaSize >= 256)
	{
		std::cout << "Narga capacity full" << std::endl;
		return;
	}
	nargas[nargaSize] = Narga(price, brand, taste);
	nargaCounts[nargaSize] = 1;
	nargaSize++;
}

void Nightclub::addAlchoholFromLine(const char* line)
{
	const char* lastDash = strrchr(line, '-');
	if (!lastDash)
	{
		std::cout << "Bad narga line" << std::endl;
		return;
	}
	char nameBuffer[129];
	int nameLen = (int)(lastDash - line);
	if (nameLen > 128)
	{
		nameLen = 128;
	}
	strncpy(nameBuffer, line, nameLen);
	nameBuffer[nameLen] = '\0';
	trimInPlace(nameBuffer);
	char priceBuffer[64];
	strncpy(priceBuffer, lastDash + 1, 63);
	priceBuffer[63] = '\0';
	trimInPlace(priceBuffer);
	double price = stringToDouble(priceBuffer);
	int indexAlchohol = findAlchohol(nameBuffer);
	if (indexAlchohol != -1) {
		++alchoholCounts[indexAlchohol];
		return;
	}
	if (alchoholSize >= MAX_ALCHOHOL)
	{
		std::cout << "Alcohol capacity full" << std::endl;
		return;
	}
	alchohols[alchoholSize] = Alchohol(nameBuffer, price);
	alchoholCounts[alchoholSize] = 1;
	++alchoholSize;
}

void Nightclub::removeBaloon(BalloonColor color)
{
	int index = findBaloon(color);
	if (index == -1)
	{
		std::cout << "Balloon not found" << std::endl;
		return;
	}
	if (--baloonCounts[index] <= 0)
	{
		for (int i = index; i < baloonSize - 1; ++i)
		{
			baloons[i] = baloons[i + 1];
			baloonCounts[i] = baloonCounts[i + 1];
		}
		--baloonSize;
	}
}

void Nightclub::removeAlchohol(const char* name)
{
	int index = findAlchohol(name);
	if (index == -1)
	{
		std::cout << "Alchohol not found" << std::endl;
		return;
	}
	if (--alchoholCounts[index] <= 0)
	{
		for (int i = index; i < alchoholSize - 1; ++i)
		{
			alchohols[i] = alchohols[i + 1];
			alchoholCounts[i] = alchoholCounts[i + 1];
		}
		--alchoholSize;
	}
}

void Nightclub::removeNarga(const char* brand, Taste taste)
{
	int idx = findNarga(brand, taste);
	if (idx == -1)
	{
		std::cout << "Narga not found" << std::endl;
		return;
	}
	if (--nargaCounts[idx] <= 0)
	{
		for (int i = idx; i < nargaSize - 1; ++i)
		{
			nargas[i] = nargas[i + 1];
			nargaCounts[i] = nargaCounts[i + 1];
		}
		--nargaSize;
	}
}

bool Nightclub::hasBaloon(BalloonColor color) const
{
	return findBaloon(color) != -1;
}

bool Nightclub::hasAlchohol(const char* name) const
{
	return findAlchohol(name) != -1;
}

bool Nightclub::hasNarga(Taste taste) const
{
	for (int i = 0; i < nargaSize; ++i)
	{
		if (nargas[i].getTaste() == taste)
		{
			return true;
		}
	}
	return false;
}

int stringToInt(const char* s)
{
	if (!s || s[0] == '\0')
	{
		return 0;
	}
	int result = 0;
	int i = 0;
	bool negative = false;

	if (s[0] == '-')
	{
		negative = true;
		i++;
	}
	else if (s[0] == '+')
	{
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (negative)
	{
		result = -result;
	}
	return result;
}

double Nightclub::getBill(const char* billFileName)
{
	std::ifstream file(billFileName);
	if (!file)
	{
		return 0.0;
	}
	double total = 0.0;
	int section = 0;
	char line[2048];
	while (file)
	{
		int len = 0;
		char charche;
		while (file.get(charche) && charche != '\n')
		{
			if (len < 2047)
			{
				line[len++] = charche;
			}
		}
		line[len] = '\0';
		if (!file && len == 0)
		{
			break;
		}
		trimInPlace(line);
		if (line[0] == '\0')
		{
			continue;
		}
		if (strcmp(line, "Alchohols:") == 0)
		{
			section = 1;
			continue;
		}
		if (strcmp(line, "Baloons:") == 0)
		{
			section = 2;
			continue;
		}
		if (strcmp(line, "Nargas:") == 0 || strcmp(line, "Narga:") == 0)
		{
			section = 3;
			continue;
		}

		if (section == 1)
		{
			int lastDash = -1;
			for (int i = 0; line[i] != '\0'; ++i)
			{
				if (line[i] == '-')
				{
					lastDash = i;
				}
			}
			if (lastDash == -1)
			{
				continue;
			}
			char nameBuf[129];
			int nameLen = lastDash;
			if (nameLen > 128)
			{
				nameLen = 128;
			}
			for (int i = 0; i < nameLen; ++i)
			{
				nameBuf[i] = line[i];
			}
			nameBuf[nameLen] = '\0';
			trimInPlace(nameBuf);
			char countBuffer[64];
			int k = 0;
			for (int i = lastDash + 1; line[i] != '\0' && k < 63; ++i)
			{
				countBuffer[k++] = line[i];
			}
			countBuffer[k] = '\0';
			trimInPlace(countBuffer);
			int count = stringToInt(countBuffer);
			int index = findAlchohol(nameBuf);
			if (index != -1)
			{
				total += alchohols[index].getPrice() * count;
			}
		}
		else if (section == 2)
		{
			char tokens[2][1025];
			if (splitLine(line, tokens, 2) < 2)
			{
				continue;
			}
			int count = stringToInt(tokens[1]);
			BalloonColor color = Baloon::colorFromString(tokens[0]);
			int index = findBaloon(color);
			if (index != -1)
			{
				total += baloons[index].getPrice() * count;
			}
		}
		else if (section == 3)
		{
			char tokens[3][1025];
			if (splitLine(line, tokens, 3) < 3)
			{
				continue;
			}
			int count = stringToInt(tokens[2]);
			Taste taste = Narga::tasteFromString(tokens[1]);
			int index = findNarga(tokens[0], taste);
			if (index != -1)
			{
				total += nargas[index].getPrice() * count;
			}
		}
	}
	return total;
}

void Nightclub::dailyProfit(Client* clients, int count)
{
	std::ofstream file("money.dat", std::ios::binary);
	if (!file)
	{
		return;
	}

	for (int i = 0; i < count; ++i)
	{
		double amount = getBill(clients[i].billFile);
		size_t nameLen = 0;
		while (clients[i].name[nameLen] != '\0')
		{
			++nameLen;
		}
		file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
		file.write(clients[i].name, nameLen);
		file.write(reinterpret_cast<const char*>(&amount), sizeof(amount));
	}
}

Client::Client() : name(nullptr), billFile(nullptr)
{
}

Client::Client(const char* name, const char* billFile)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->billFile = new char[strlen(billFile) + 1];
	strcpy(this->billFile, billFile);
}

Client::Client(const Client& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->billFile = new char[strlen(other.billFile) + 1];
	strcpy(this->billFile, other.billFile);
}

Client& Client::operator=(const Client& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] billFile;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		billFile = new char[strlen(other.billFile) + 1];
		strcpy(billFile, other.billFile);
	}
	return *this;
}

Client::~Client()
{
	delete[] name;
	delete[] billFile;
}
