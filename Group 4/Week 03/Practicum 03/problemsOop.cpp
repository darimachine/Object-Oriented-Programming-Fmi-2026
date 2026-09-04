#include "problemsOop1.h"

	Jedi::Jedi() {
		name = "";
		age = 0;
		power = 0;
		saber.c = Color::RED;
		saber.t = Type::SINGLEBLADED;
	}

	Jedi::Jedi(string _name, unsigned int _age, unsigned int _power, LightSaber _saber) : name(_name), age(_age), power(_power) {
		saber.c = _saber.c;
		saber.t = _saber.t;
	}

	Jedi::Jedi(string _name, unsigned int _age, unsigned int _power, Color c, Type t) : name(_name), age(_age), power(_power) {
		saber.c = c;
		saber.t = t;
	}

	Jedi* JediCollection::getJedis()
	{
		return jedis;
	}
	
	int JediCollection::jedisCount()
	{
		return size;
	}

	void JediCollection::addJedi(Jedi j)
	{
		if (size < MAX_JEDIS) {
			jedis[size++] = j;
		}
		else cout<<"The Jedi group is full! Please try again later.\n";
	}

	void JediCollection::removeJedi(string name)
	{
		int jPos = findJedi(name);
		if (jPos < 0) {
			cout << "Jedi not found!\n";
		}
		else {
			for (int i = jPos; i < size-1; i++)
			{
				jedis[i] = jedis[i + 1];
			} 
			Jedi j;//jedi by default
			jedis[size - 1] = j;
			size--;
		}
	}

	void JediCollection::print() const {
		for (int i = 0; i < size; i++)
		{
			std::printf("Jedy: %s, Age: %d, Power: %d, saber (color: %s, type: %s)\n",
				jedis[i].name.c_str(),
				jedis[i].age,
				jedis[i].power,
				getSaberColorName(jedis[i].saber).c_str(),
				getSaberTypeName(jedis[i].saber).c_str()
			);
		}
	}

	string JediCollection::getColorName(Color col) const {
		string color;
		switch (col) {
		case Color::BLUE: {
			color = "blue";
			break;
		}
		case Color::GREEN: {
			color = "green";
			break;
		}
		case Color::PURPLE: {
			color = "purple";
			break;
		}
		case Color::RED: {
			color = "red";
			break;
		}
		case Color::YELLOW: {
			color = "yellow";
			break;
		}
		default:
			break;
		}
		return color;
	}

	string JediCollection::getSaberColorName(LightSaber saber) const {
		
		return getColorName(saber.c);
	}

	string JediCollection::getSaberTypeName(LightSaber saber) const {
		return getTypeName(saber.t);
	}

	string JediCollection::getTypeName(Type t) const {
		string _type = "";
		switch (t) {
		case Type::CROSSGUARD: {
			_type = "crossguard";
			break;
		}
		case Type::DOUBLE_BLADED: {
			_type = "double bladed";
			break;
		}
		case Type::SINGLEBLADED: {
			_type = "single bladed";
			break;
		}

		default:
			break;
		}
		return _type;
	}

	int JediCollection::findJedi(string name) {
		for (int i = 0; i < MAX_JEDIS; ++i) {
			if (name == jedis[i].name) {
				return i;//jedi position
			}
		}
		return -1;
	}


	void JediData::sortByAge(JediCollection& collection) {
		int size = collection.jedisCount();
		Jedi* jedis = collection.getJedis();
		for (int i = size-1; i > 0; i--) {
			for (int j = size-1; j > 0; j--) {
				if (jedis[j].age < jedis[j - 1].age) {
					Jedi t = jedis[j];
					jedis[j] = jedis[j - 1];
					jedis[j - 1] = t;
				}
			}
		}
	}


	void JediData::sortByPower(JediCollection& collection) {
		int size = collection.jedisCount();
		Jedi* jedis = collection.getJedis();
		for (int i = size - 1; i > 0; i--) {
			for (int j = size - 1; j > 0; j--) {
				if (jedis[j].power < jedis[j - 1].power) {
					Jedi t = jedis[j];
					jedis[j] = jedis[j - 1];
					jedis[j - 1] = t;
				}
			}
		}
	}

	Color JediData::mostPopularSaberColor(JediCollection collection)
	{
		int colors[5] = { 0 };

		int size = collection.jedisCount();
		Jedi* jedis = collection.getJedis();
		for (int i = 0; i < size; i++)
		{
			LightSaber j_saber = jedis[i].saber;
			colors[(int)j_saber.c]++;
		}
		int most = 0;
		int maxcol = colors[0];
		for (int i = 1; i < 5; i++)
		{
			if (colors[i] > maxcol) {
				maxcol = colors[i];
				most = i;
			}
		}
		return static_cast<Color>(most);
	}

	Type JediData::mostPopularSaberType(JediCollection collection)
	{
		int types[3] = { 0 };

		int size = collection.jedisCount();
		Jedi* jedis = collection.getJedis();
		for (int i = 0; i < size; i++)
		{
			LightSaber j_saber = jedis[i].saber;
			types[(int)j_saber.t]++;
		}
		int most = 0;
		int maxtype = types[0];
		for (int i = 1; i < 5; i++)
		{
			if (types[i] > maxtype) {
				maxtype = types[i];
				most = i;
			}
		}
		return static_cast<Type>(most);
	}

	void JediIO::saveToTxt(JediCollection collection, string fileName)
	{
		ofstream saveFile(fileName);
		if (!saveFile) {
			cout << "Error saving file!" << endl;
			return;
		}
		int size = collection.jedisCount();
		Jedi* jedis = collection.getJedis();
		for (int i = 0; i < size; i++)
		{
			Jedi j = jedis[i];
			saveFile << j.name << " " << j.age << " " << j.power << " " << (int) j.saber.c << " " << (int) j.saber.t << endl;
		}
		
		saveFile.close();
	}

	void JediIO::saveToBinary(JediCollection collection, string fileName)
	{
		ofstream saveFile(fileName, std::ios::binary);
		if (!saveFile) {
			cout << "Error saving file!" << endl;
			return;
		}
		Jedi* jedis = collection.getJedis();
		int size = collection.jedisCount();
		saveFile.write((char*)&size, sizeof(size));
		for (int i = 0; i < size; ++i)
		{
			Jedi jedi = jedis[i];
			saveFile.write(jedi.name.c_str(), 50);
			saveFile.write((char*)&jedi.age, sizeof(jedi.age));
			saveFile.write((char*)&jedi.power, sizeof(jedi.power));
			int color = int(jedi.saber.c);
			int type = int(jedi.saber.t);
			saveFile.write((char*)&color, sizeof(color));
			saveFile.write((char*)&type, sizeof(type));
		}

		saveFile.close();
	}

	JediCollection JediIO::readFromTxt(string fileName) {
		JediCollection collection;
		ifstream loadFile(fileName);
		if (!loadFile) {
			cout << "Error reading from file!" << endl;
			return collection;
		}
		while (!loadFile.eof())
		{
			Jedi jedi;
			int colorInt, typeInt;
			loadFile >> jedi.name >> jedi.age >> jedi.power >> colorInt >> typeInt;
			if (loadFile.fail())
			{
				break;
			}
			jedi.saber.c = Color(colorInt);
			jedi.saber.t = Type(typeInt);

			collection.addJedi(jedi);
		}
		loadFile.close();
		cout << "Jedis were loaded from file " << fileName << endl;

		return collection;
	}

	JediCollection JediIO::readFromBinary(string fileName) {
		JediCollection collection;
		ifstream loadFile(fileName, std::ios::binary);
		if (!loadFile) {
			cout << "Error reading from file!" << endl;
			return collection;
		}

		int size = 0;
		loadFile.read((char*)&size, sizeof(size));
		for (int i = 0; i < size; ++i)
		{
			Jedi jedi;
			char namearr[50];
			loadFile.read(namearr, sizeof(namearr));
			jedi.name = string(namearr);
			loadFile.read((char*)&jedi.age, sizeof(jedi.age));
			loadFile.read((char*)&jedi.power, sizeof(jedi.power));
			int colorInt, typeInt;
			loadFile.read((char*)&colorInt, sizeof(colorInt));
			loadFile.read((char*)&typeInt, sizeof(typeInt));
			jedi.saber.c = Color(colorInt);
			jedi.saber.t = Type(typeInt);
			collection.addJedi(jedi);
		}

		loadFile.close();
		cout << "Jedis were loaded from file " << fileName << endl;

		return collection;
	}

int main()
{
	JediCollection collection;
	for (int i = 0; i < 10; ++i) {
		string name = "Jedi" + std::to_string(i+1);

		LightSaber s;
		s.c = Color::RED;
		s.t = Type::SINGLEBLADED;
		int age = 30;
		int power = 90;
		Jedi j(name, age, power, s);
		collection.addJedi(j);
	}

	collection.print(); cout << endl;
	JediIO jio;
	jio.saveToBinary(collection, "c:\\temp\\Ani.dat");
	jio.saveToTxt(collection, "c:\\temp\\Ani.txt");

	JediCollection collection_bin = jio.readFromBinary("c:\\temp\\Ani.dat");
	collection_bin.print(); cout << endl;

	JediCollection collection_txt = jio.readFromTxt("c:\\temp\\Ani.txt");
	collection_txt.print(); cout << endl;
}