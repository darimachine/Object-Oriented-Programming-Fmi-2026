#pragma once
#include <fstream>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

const int MAX_JEDIS = 100;

enum class Color { RED, YELLOW, GREEN, BLUE, PURPLE };
enum class Type { SINGLEBLADED, DOUBLE_BLADED, CROSSGUARD };

struct LightSaber {
	Color c;
	Type t;
};
struct Jedi {
	string name;
	unsigned int age;
	unsigned int power;
	LightSaber saber;

	Jedi();

	Jedi(string _name, unsigned int _age, unsigned int _power, LightSaber _saber);

	Jedi(string _name, unsigned int _age, unsigned int _power, Color c, Type t);
};

	class JediCollection {

	public:

		Jedi* getJedis();

		int jedisCount();

		void addJedi(Jedi j);

		void removeJedi(string name);

		void print() const;

		string getColorName(Color col) const;

		string getSaberColorName(LightSaber saber) const;

		string getSaberTypeName(LightSaber saber) const;

		string getTypeName(Type t) const;

	private:

		int findJedi(string name);



		int size = 0;
		Jedi jedis[MAX_JEDIS];
	};

	class JediData {
	public:
		static void sortByAge(JediCollection& collection);

		static void sortByPower(JediCollection& collection);

		static Color mostPopularSaberColor(JediCollection collection);

		static Type mostPopularSaberType(JediCollection collection);
	};

	class JediIO {
	public:
		static void saveToTxt(JediCollection collection, string fileName);

		static void saveToBinary(JediCollection collection, string fileName);

		static JediCollection readFromTxt(string fileName);

		static JediCollection readFromBinary(string fileName);
	};