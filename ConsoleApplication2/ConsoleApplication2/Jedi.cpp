#include <iostream>
#include <cstring>
#include <fstream>

constexpr int MAX_NAME = 50;
constexpr int MAX_JEDI = 100;

enum class LightSaberColor {
	BLUE,
	RED,
	YELLOW,
	GREEN,
	PURPLE
};

enum class LightSaberType {
	SINGLE_BLADED,
	DOUBLE_BLADED,
	CROSSGUARD
};

struct LightSaber {
	LightSaberColor color;
	LightSaberType type;

	LightSaber() : color(LightSaberColor::BLUE), type(LightSaberType::SINGLE_BLADED){

	}
};

struct Jedi {
	char name[MAX_NAME];
	unsigned int age;
	unsigned int powerLevel;
	LightSaber lightSaber;

	Jedi() : age(0), powerLevel(0) {
		name[0] = '\0';
	}

	Jedi(char* newName, int age, int power, const LightSaber& saber) 
		: age(age), powerLevel(power), lightSaber(saber) 
	{
		std::strncpy(name, newName, MAX_NAME - 1);
		name[MAX_NAME - 1] = '\0'; 
	}

	Jedi(char* newName, int age, int power, LightSaberColor color, LightSaberType type)
		: age(age), powerLevel(power)
	{
		std::strncpy(name, newName, MAX_NAME - 1);
		name[MAX_NAME - 1] = '\0';

		lightSaber.color = color;
		lightSaber.type = type;
	}
};

class JediCollection {
	Jedi jedis[MAX_JEDI];
	int jediCount;

public:

	int getJediCount() const {
		return jediCount;
	}

	Jedi& getJedi(int index) {
		if (index >= 0 && index < jediCount) {
			return jedis[index];
		} else {
			std::cout <<"Invalid Jedi index" << std::endl;
		}
	}

	const Jedi& getJedi(int index) const {
		if (index >= 0 && index < jediCount) {
			return jedis[index];
		}
		else {
			std::cout << "Invalid Jedi index" << std::endl;
		}
	}

	JediCollection() : jediCount(0)
	{

	}

	void addJedi(const Jedi& jedi) {
		if (jediCount < MAX_JEDI) {
			jedis[jediCount++] = jedi;
		} else {
			std::cout << "Cannot add more Jedis!" << std::endl;
		}
	}

	void removeJedi(const char* name) {
		for (size_t i = 0; i < jediCount; i++)
		{
			if ((strcmp(jedis[i].name, name) == 0)) {
				for (size_t j = i; j < jediCount - 1; j++)
				{
					jedis[j] = jedis[j + 1];
				}
				jediCount--;
				return;
			}
		}

		std::cout << "Jedi not found!" << std::endl;
	}

	void Print() {
		for (size_t i = 0; i < jediCount; i++)
		{
			std::cout << "Jedi " << i + 1 << ":" << std::endl;
			std::cout << "Name: " << jedis[i].name << std::endl;
			std::cout << "Age: " << jedis[i].age << std::endl;
			std::cout << "Power Level: " << jedis[i].powerLevel << std::endl;
			std::cout << "Light Saber: " << static_cast<int>(jedis[i].lightSaber.color) << ", " 
				<< static_cast<int>(jedis[i].lightSaber.type) << std::endl;

		}
	}
};

void mySwap(Jedi& a, Jedi& b) {
	Jedi temp = a;
	a = b;
	b = temp;
}

class JediData {
public:
	void sortByAge(JediCollection& collection) {
		int jediCount = collection.getJediCount();

		for (size_t i = 0; i < jediCount - 1; i++)
		{
			for (size_t j = 0; j < jediCount - i - 1; j++)
			{
				if (collection.getJedi(i).age > collection.getJedi(j + 1).age) {
					mySwap(collection.getJedi(j), collection.getJedi(j + 1));
				}
			}
		}
	}

	void sortByPower(JediCollection& collection) {
		int jediCount = collection.getJediCount();

		for (size_t i = 0; i < jediCount - 1; i++)
		{
			for (size_t j = 0; j < jediCount - i - 1; j++)
			{
				if (collection.getJedi(i).powerLevel > collection.getJedi(j + 1).powerLevel) {
					mySwap(collection.getJedi(j), collection.getJedi(j + 1));
				}
			}
		}
	}

	LightSaberColor mostPopularSaberColor(const JediCollection& collection) {
		int colorCount[5] = { 0 };
		int max = colorCount[0];
		int maxIndex = 0;

		int jedyCount = collection.getJediCount();

		for (size_t i = 0; i < jedyCount; i++)
		{
			LightSaberColor color = collection.getJedi(i).lightSaber.color;
			colorCount[static_cast<int>(color)]++;
		}

		for (size_t i = 0; i < 5; i++)
		{
			if (colorCount[i] > max) {
				max = colorCount[i];
				maxIndex = i;
			}
		}

		return static_cast<LightSaberColor>(maxIndex);
	}

	LightSaberType mostPopularSaberType(const JediCollection& collection) {
		int typeCount[3] = { 0 };
		int max = typeCount[0];
		int maxIndex = 0;

		int jedyCount = collection.getJediCount();

		for (size_t i = 0; i < jedyCount; i++)
		{
			LightSaberType type = collection.getJedi(i).lightSaber.type;
			typeCount[static_cast<int>(type)]++;
		}

		for (size_t i = 0; i < 3; i++)
		{
			if (typeCount[i] > max) {
				max = typeCount[i];
				maxIndex = i;
			}
		}

		return static_cast<LightSaberType>(maxIndex);
	}
};

class JediIO {
public:

	void saveToTxt(const JediCollection& collection, const char* fileName) {
		std::ofstream file(fileName);
		if (!file.is_open()) {
			return;
		}

		saveToTxt(collection, file);
		file.close();
	}

	void saveToTxt(const JediCollection& collection, std::ofstream& outStream) {
		int count = collection.getJediCount();
		outStream << count << '\n'; 

		for (int i = 0; i < count; i++) {
			Jedi j = collection.getJedi(i);

			outStream << j.name << '\n';
			outStream << j.age << " "
				<< j.powerLevel << " "
				<< static_cast<int>(j.lightSaber.color) << " "
				<< static_cast<int>(j.lightSaber.type) << '\n';
		}
	}

	JediCollection readFromTxt(const char* fileName) {
		JediCollection tempCollection;
		std::ifstream file(fileName);
		if (!file.is_open()) {
			return;
		}

		tempCollection = readFromTxt(file);
		file.close();

		return tempCollection;
	}

	JediCollection readFromTxt(std::ifstream& inStream) {
		JediCollection tempCollection;

		int count;
		inStream >> count;

		for (int i = 0; i < count; i++) {
			char tempName[50];
			int tempAge, tempPower, tempColor, tempType;

			inStream.getline(tempName, 50);
			inStream >> tempAge >> tempPower >> tempColor >> tempType;

			Jedi newJedi(tempName, tempAge, tempPower,
				static_cast<LightSaberColor>(tempColor),
				static_cast<LightSaberType>(tempType));

			tempCollection.addJedi(newJedi);
		}

		return tempCollection;
	}

	void saveToBinary(const JediCollection& collection, const char* fileName) {
		std::ofstream file(fileName, std::ios::binary); 
		if (!file.is_open()) {
			return;
		}

		saveToBinary(collection, file);
		file.close();

	}

	void saveToBinary(const JediCollection& collection, std::ofstream& outStream) {
		int count = collection.getJediCount();

		outStream.write(reinterpret_cast<const char*>(&count), sizeof(count));

		for (int i = 0; i < count; i++) {
			Jedi j = collection.getJedi(i);
			outStream.write(reinterpret_cast<const char*>(&j), sizeof(Jedi));
		}
	}

	JediCollection readFromBinary(const char* fileName) {
		JediCollection tempCollection;
		std::ifstream file(fileName, std::ios::binary);
		if (!file.is_open()) {
			return;
		}

		tempCollection = readFromBinary(file);
		file.close();

		return tempCollection;
	}

	JediCollection readFromBinary(std::ifstream& inStream) {
		JediCollection tempCollection;

		int count = 0;
		if (inStream.read(reinterpret_cast<char*>(&count), sizeof(count))) {

			for (int i = 0; i < count; i++) {
				Jedi tempJedi; 
				inStream.read(reinterpret_cast<char*>(&tempJedi), sizeof(Jedi));

				tempCollection.addJedi(tempJedi);
			}
		}

		return tempCollection;
	}
};
int main()
{

}

