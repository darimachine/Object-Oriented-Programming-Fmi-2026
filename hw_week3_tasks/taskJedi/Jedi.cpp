#define _CRT_SECURE_NO_WARNINGS
#include "Jedi.h"
#include <iostream>
using std::cout;


static void safeCopyName(char* destination, const char* source)
{
	if (!source || source[0] == '\0')
	{
		cout << "Jedi name cannot be empty.";
		return;
	}
	if (strlen(source) > Jedi::MAX_NAME_LENGTH)
	{
		cout << "Jedi name exceeds 50 characters.";
		return;
	}

	strncpy(destination, source, Jedi::MAX_NAME_LENGTH);
	destination[Jedi::MAX_NAME_LENGTH] = '\0';
}

LightSaber::LightSaber(SaberColor color, SaberType type) : color(color), type(type)
{

}

Jedi::Jedi(const char* name, int age, int power, const LightSaber& saber) : age(age), power(power), saber(saber)
{
	safeCopyName(this->name, name);
}

Jedi::Jedi(const char* name, int age, int power, SaberColor color, SaberType type) : Jedi(name, age, power, LightSaber(color, type))
{

}

JediCollection::JediCollection() : count(0)
{

}

void JediCollection::addJedi(const Jedi& jedi)
{
	if (count >= MAX_JEDIS)
	{
		return;
	}
	jedis[count++] = jedi;
}

void JediCollection::removeJedi(const char* name)
{
	for (int i = 0; i < count; i++)
	{
		if (strcmp(jedis[i].name, name) == 0)
		{
			for (int j = i; j < count - 1; j++)
			{
				jedis[j] = jedis[j + 1];
			}
			count--;
			return;
		}
	}
}

void JediCollection::print() const
{
	for (int i = 0; i < count; i++)
	{
		cout << jedis[i].name
			<< " Age:" << jedis[i].age
			<< " Power:" << jedis[i].power
			<< std::endl;
	}
}


int JediCollection::size() const { return count; }

Jedi& JediCollection::getJedi(int index)
{
	if (index < 0 || index >= count)
	{
		cout << "Index out of range";
	}
	return jedis[index];
}

const Jedi& JediCollection::getJedi(int index) const
{
	if (index < 0 || index >= count)
	{
		cout << "Index out of range";
	}
	return jedis[index];
}

void JediCollection::setJedi(int index, const Jedi& jedi)
{
	if (index < 0 || index >= count)
	{
		cout << "Index out of range";
	}
	jedis[index] = jedi;
}

void JediCollection::swapJedi(int i, int j)
{
	if (i < 0 || i >= count || j < 0 || j >= count)
	{
		cout << "Index out of range";
		return;
	}
	Jedi tmp = jedis[i];
	jedis[i] = jedis[j];
	jedis[j] = tmp;
}

void JediData::sortByAge(JediCollection& collection)
{
	int n = collection.size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			Jedi& current = collection.getJedi(j);
			Jedi& next = collection.getJedi(j + 1);

			if (current.age > next.age)
			{
				collection.swapJedi(j, j + 1);
			}
		}
	}
}

void JediData::sortByPower(JediCollection& collection)
{
	int n = collection.size();
	for (unsigned int i = 0; i < n - 1; ++i)
	{
		for (unsigned int j = 0; j < n - i - 1; ++j)
		{
			if (collection.getJedi(j).power > collection.getJedi(j + 1).power)
			{
				collection.swapJedi(j, j + 1);
			}
		}
	}
}

SaberColor JediData::mostPopularSaberColor(const JediCollection& collection)
{
	int colorFrequency[5] = {};
	int totalJedis = collection.size();
	for (int jediIndex = 0; jediIndex < totalJedis; ++jediIndex)
	{
		int colorIndex = int(collection.getJedi(jediIndex).saber.color);
		colorFrequency[colorIndex]++;
	}
	int mostPopularIndex = 0;
	for (int colorIndex = 1; colorIndex < 5; ++colorIndex)
	{
		if (colorFrequency[colorIndex] > colorFrequency[mostPopularIndex])
		{
			mostPopularIndex = colorIndex;
		}
	}
	return SaberColor(mostPopularIndex);
}

SaberType JediData::mostPopularSaberType(const JediCollection& collection)
{
	int typeFrequency[3] = {};
	int totalJedis = collection.size();
	for (int jediIndex = 0; jediIndex < totalJedis; ++jediIndex)
	{
		int typeIndex = int(collection.getJedi(jediIndex).saber.type);
		typeFrequency[typeIndex]++;
	}
	int mostPopularIndex = 0;
	for (int typeIndex = 1; typeIndex < 3; ++typeIndex)
	{
		if (typeFrequency[typeIndex] > typeFrequency[mostPopularIndex])
		{
			mostPopularIndex = typeIndex;
		}
	}
	return SaberType(mostPopularIndex);
}

void JediIO::saveToBinary(const JediCollection& collection, const char* fileName)
{
	std::ofstream out(fileName, std::ios::binary);
	if (!out)
	{
		cout << "Cannot open file for writing.";
		return;
	}
	saveToBinary(out, collection);
}

JediCollection JediIO::readFromBinary(const char* fileName)
{
	std::ifstream in(fileName, std::ios::binary);
	if (!in) 
	{
		cout << "Cannot open file for reading.";
		return JediCollection();;
	}
	return readFromBinary(in);
}

void JediIO::saveToBinary(std::ofstream& out, const JediCollection& collection)
{
	int totalJedis = collection.size();
	out.write((char*)&totalJedis, sizeof(totalJedis)); 
	for (int jediIndex = 0; jediIndex < totalJedis; ++jediIndex)
	{
		const Jedi& jedi = collection.getJedi(jediIndex);
		out.write(jedi.name, sizeof(jedi.name));
		out.write((char*)&jedi.age, sizeof(jedi.age));
		out.write((char*)&jedi.power, sizeof(jedi.power));
		int color = int(jedi.saber.color);
		int type = int(jedi.saber.type);
		out.write((char*)&color, sizeof(color));
		out.write((char*)&type, sizeof(type));
	}
}

JediCollection JediIO::readFromBinary(std::ifstream& in)
{
	JediCollection collection;
	int totalJedis = 0;
	in.read((char*)&totalJedis, sizeof(totalJedis));
	for (int jediIndex = 0; jediIndex < totalJedis; ++jediIndex)
	{
		Jedi jedi;
		in.read(jedi.name, sizeof(jedi.name));
		in.read((char*)&jedi.age, sizeof(jedi.age));
		in.read((char*)&jedi.power, sizeof(jedi.power));
		int colorInt, typeInt;
		in.read((char*)&colorInt, sizeof(colorInt));
		in.read((char*)&typeInt, sizeof(typeInt));
		jedi.saber.color = SaberColor(colorInt);
		jedi.saber.type = SaberType(typeInt);
		collection.addJedi(jedi);
	}
	return collection;
}

void JediIO::saveToTxt(const JediCollection& collection, const char* fileName)
{
	std::ofstream out(fileName);
	if (!out)
	{
		cout << "Cannot open file for writing.";
		return;
	}
	saveToTxt(out, collection);
}

JediCollection JediIO::readFromTxt(const char* fileName)
{
	std::ifstream in(fileName);
	if (!in)
	{
		cout << "Cannot open file for reading.";
		return JediCollection();;
	}
	return readFromTxt(in);
}

void JediIO::saveToTxt(std::ostream& out, const JediCollection& collection)
{
	int totalJedis = collection.size();
	for (int i = 0; i < totalJedis; ++i)
	{
		const Jedi& jedi = collection.getJedi(i);
		out << jedi.name << " "
			<< jedi.age << " "
			<< jedi.power << " "
			<< int(jedi.saber.color) << " "
			<< int(jedi.saber.type) << "\n";
	}
}

JediCollection JediIO::readFromTxt(std::istream& in)
{
	JediCollection collection;
	while (!in.eof())
	{
		Jedi jedi;
		int colorInt, typeInt;
		in >> jedi.name >> jedi.age >> jedi.power >> colorInt >> typeInt;
		if (in.fail())
		{
			break;
		}
		jedi.saber.color = SaberColor(colorInt);
		jedi.saber.type = SaberType(typeInt);
		collection.addJedi(jedi);
	}
	return collection;
}