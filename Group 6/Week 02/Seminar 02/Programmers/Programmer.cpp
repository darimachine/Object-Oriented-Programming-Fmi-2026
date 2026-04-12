#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
using std::endl;
using std::cout;
constexpr char DELIM = ',';
constexpr int MAX_LENGTH = 32;
constexpr int MAX_LANGUAGES = 8;
constexpr int MIN_AGE = 18;
constexpr int MIN_SALARY = 2500;
constexpr int MAX_SALARY = 5000;

typedef unsigned char byte;

enum class Languages : byte {
	Python = 1 << 0,
	Cpp = 1 << 1,
	Java = 1<<2,
	Go = 1<<3,
};
class Programmer {
	char name[MAX_LENGTH];
	unsigned age;
	double salary;
	byte languages = 0;

	void setAge(unsigned age) {
		if (age < MIN_AGE) {
			return;
		}
		this->age = age;
	}
	void setName(const char* name) {
		if (!name || strlen(name) > MAX_LENGTH) {
			return;
		}
		strcpy(this->name, name);
	}
public:
	Programmer() = default;

	Programmer(const char* name, unsigned age, double salary) {
		setName(name);
		setAge(age);
		setSalary(salary);
	}
	void setSalary(double _salary) {
		if (_salary < MIN_SALARY || _salary >MAX_SALARY) {
			return;
		}
		this->salary = _salary;
	}
	void learnLanguage(const Languages& lang) {
		languages |= (byte)lang;
	}
	bool canWorkWith(const Languages& lang) const {
		return languages & (byte)lang;
	}
	void setLanguages(const char* lang) {
		while (*lang) {
			switch (*lang) {
				case 'p': {
					learnLanguage(Languages::Python);
					break;
				}
				case 'c': {
					learnLanguage(Languages::Cpp);
					break;
				}
				case 'j': {
					learnLanguage(Languages::Java);
					break;
				}
				case 'g': {
					learnLanguage(Languages::Go);
					break;
				}
			}
			lang++;
		}
	}
	
	const char* byteToLanguage(byte ch) const{
		switch (ch) {
			case 1<<0: {
				return "Python";
			}
			case 1<<1: {
				return "C++";
			}
			case 1<<2: {
				return "Java";
			}
			case 1<<3: {
				return "Go";
			}
		}
	}
	void printLanguages() const {
		for (int i = 0; i < MAX_LANGUAGES; i++) {
			byte mask = 1 << i;
			if (languages & mask) {
				cout<<byteToLanguage(mask)<<" ";
			}

		}
	}

	void print() const {
		cout << name << " | " << age << " | " << salary << " | ";
		printLanguages();
	}

};
constexpr int BUFFER_SIZE = 1024;

int getCharCount(std::ifstream& ifs, char ch) {
	int currPos = ifs.tellg();
	int counter = 0;
	while (true) {
		char currentCh = ifs.get();
		if (ifs.eof()) {
			break;
		}
		if (currentCh == ch) {
			counter++;
		}
	}
	ifs.clear();//!!!!!!!!!!! IMPORTANT
	ifs.seekg(currPos);
	return counter;
}
class Client {
	Programmer* programmers;
	int programmersCount=0;

	void parseRow(Programmer& programmer, const char* buffer) {
		std::stringstream ss(buffer);
		char name[MAX_LENGTH];
		ss.getline(name, MAX_LENGTH, DELIM);

		unsigned age;
		ss >> age;
		ss.ignore();

		double salary;
		ss >> salary;
		ss.ignore();

		char languages[MAX_LANGUAGES];
		ss.getline(languages, MAX_LANGUAGES);
		Programmer prog(name, age, salary);
		prog.setLanguages(languages);
		programmer = prog;

	}
	void readTable(const char* filename) {
		std::ifstream ifs(filename);
		if (!ifs.is_open()) {
			//throw
			return;
		}

		char buffer[BUFFER_SIZE];
		ifs.getline(buffer, BUFFER_SIZE);// skipping first line
		programmersCount = getCharCount(ifs, '\n') + 1;
		programmers = new Programmer[programmersCount];

		int index = 0;
		while (!ifs.eof()) {
			ifs.getline(buffer, BUFFER_SIZE);
			parseRow(programmers[index], buffer);
			index++;
		}
	}
public:
	Client(const char* fileName) {
		readTable(fileName);
	}
	int getProgrammerCount() const {
		return programmersCount;
	}
	void showProgrammers() const {
		for (int i = 0; i < programmersCount; i++)
		{
			programmers[i].print();
			cout << endl;
		}
	}
	~Client() {
		delete[] programmers;
	}
};
int main() {
	Client client("Programmers.csv");
	client.showProgrammers();
}