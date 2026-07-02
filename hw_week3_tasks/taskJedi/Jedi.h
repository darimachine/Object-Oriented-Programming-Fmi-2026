#pragma once 
#include <istream>
#include <ostream>
#include <fstream>

enum class SaberColor
{
	RED,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
};

enum class SaberType
{
	SINGLE_BLADED,
	DOUBLE_BLADED,
	CROSSGUARD,
};

struct LightSaber
{
	SaberColor color;
	SaberType  type;
	LightSaber(SaberColor color = SaberColor::BLUE, SaberType  type = SaberType::SINGLE_BLADED);
};

struct Jedi
{
	static const int MAX_NAME_LENGTH = 50;
	char name[MAX_NAME_LENGTH + 1];
	int age;
	int power;
	LightSaber saber;

	Jedi() = default;
	Jedi(const char* name, int age, int power, const LightSaber& saber);
	Jedi(const char* name, int age, int power, SaberColor color, SaberType type);
};

class JediCollection
{
private:
	static const int MAX_JEDIS = 100;
	Jedi jedis[MAX_JEDIS];
	int count = 0;

public:
	JediCollection();
	void addJedi(const Jedi& jedi);
	void removeJedi(const char* name);
	void print() const;
	int size() const;
	Jedi& getJedi(int index); 
	const Jedi& getJedi(int index) const;
	void setJedi(int index, const Jedi& jedi);
	void swapJedi(int i, int j);
};

class JediData 
{
public:
	static void sortByAge(JediCollection& collection);
	static void sortByPower(JediCollection& collection);
	static SaberColor mostPopularSaberColor(const JediCollection& collection);
	static SaberType  mostPopularSaberType(const JediCollection& collection);
};

class JediIO
{
public:
	static void saveToBinary(const JediCollection& collection, const char* fileName);
	static JediCollection readFromBinary(const char* fileName);

	static void saveToBinary(std::ofstream& out, const JediCollection& collection);
	static JediCollection readFromBinary(std::ifstream& in);

	static void saveToTxt(const JediCollection& collection, const char* fileName);
	static JediCollection readFromTxt(const char* fileName);

	static void saveToTxt(std::ostream& out, const JediCollection& collection);
	static JediCollection readFromTxt(std::istream& in);
};