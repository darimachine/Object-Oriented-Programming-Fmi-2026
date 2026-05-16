
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const int SIZE_NAME = 50;
const int CAPACITY = 100;

enum Color {
    RED, YELLOW, GREEN, BLUE, PURPLE, COLOR_UNKNOWN
};

enum Type {
    SINGLEBLADED, DOUBLE_BLADED, CROSSGUARD, TYPE_UNKNOWN
};

struct LightSaber {
    Color color;
    Type type;
};

struct Jedi {

    char name[SIZE_NAME];
    unsigned age;
    unsigned power;
    LightSaber saber;

    Jedi() {
        name[0] = '\0';
        age = 0;
        power = 0;
        saber.color = COLOR_UNKNOWN;
        saber.type = TYPE_UNKNOWN;
    }

    Jedi(const char* n, unsigned a, unsigned p, LightSaber s) {
        strcpy(name, n);
        age = a;
        power = p;
        saber = s;
    }

    Jedi(const char* n, unsigned a, unsigned p, Color c, Type t) {
        strcpy(name, n);
        age = a;
        power = p;
        saber.color = c;
        saber.type = t;
    }
};

class JediCollection {

private:

    Jedi jedi[CAPACITY];
    int numJedi;

public:

    JediCollection() {
        numJedi = 0;
    }

    void addJedi(const Jedi& newJedi) {

        if (numJedi == CAPACITY) {
            cout << "No more capacity!\n";
            return;
        }

        jedi[numJedi++] = newJedi;
    }

    void removeJedi(const char* name) {

        for (int i = 0; i < numJedi; i++) {

            if (strcmp(jedi[i].name, name) == 0) {

                for (int j = i; j < numJedi - 1; j++) {
                    jedi[j] = jedi[j + 1];
                }

                numJedi--;
                return;
            }
        }
    }

    int getNumJedi() const {
        return numJedi;
    }

    Jedi& getJedi(int index) {
        return jedi[index];
    }

    const Jedi& getJedi(int index) const {
        return jedi[index];
    }
    const char* colorToStr(Color c) {
        switch (c) {
        case Color::RED:    return "red";
        case Color::BLUE:   return "blue";
        case Color::GREEN:  return "green";
        case Color::PURPLE: return "purple";
        case Color::YELLOW: return "yellow";
        default:            return "unknown";
        }
    }
    const char* typeToStr(Type c) {
        switch (c) {
        case Type::SINGLEBLADED:    return "singlebladed";
        case Type::DOUBLE_BLADED:   return "double bladed";
        case Type::CROSSGUARD:  return "crossguard";
        default:            return "unknown";
        }
    }
    void print(){

        for (int i = 0; i < numJedi; i++) {

            cout << "Jedi " << i + 1 << endl;

            cout << "Name: " << jedi[i].name << endl;
            cout << "Age: " << jedi[i].age << endl;
            cout << "Power: " << jedi[i].power << endl;
            cout << "Color: " << colorToStr(jedi[i].saber.color) << endl;
            cout << "Type: " << typeToStr(jedi[i].saber.type) << endl;

            cout << endl;
        }
    }
};

class JediData {

public:

    static void sortByAge(JediCollection& collection) {

        int n = collection.getNumJedi();

        for (int i = 0; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {

                if (collection.getJedi(i).age > collection.getJedi(j).age) {

                    Jedi temp = collection.getJedi(i);
                    collection.getJedi(i) = collection.getJedi(j);
                    collection.getJedi(j) = temp;
                }
            }
        }
    }

    static void sortByPower(JediCollection& collection) {

        int n = collection.getNumJedi();

        for (int i = 0; i < n - 1; i++) {

            for (int j = i + 1; j < n; j++) {

                if (collection.getJedi(i).power > collection.getJedi(j).power) {

                    Jedi temp = collection.getJedi(i);
                    collection.getJedi(i) = collection.getJedi(j);
                    collection.getJedi(j) = temp;
                }
            }
        }
    }

    static Color mostPopularSaberColor(const JediCollection& collection) {

        int arr[6] = { 0 };

        for (int i = 0; i < collection.getNumJedi(); i++) {

            arr[collection.getJedi(i).saber.color]++;
        }

        int maxIndex = 0;

        for (int i = 1; i < 6; i++) {

            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        return (Color)maxIndex;
    }

    static Type mostPopularSaberType(const JediCollection& collection) {

        int arr[4] = { 0 };

        for (int i = 0; i < collection.getNumJedi(); i++) {

            arr[collection.getJedi(i).saber.type]++;
        }

        int maxIndex = 0;

        for (int i = 1; i < 4; i++) {

            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        return (Type)maxIndex;
    }
};

ostream& operator<<(ostream& os, const Jedi& j) {

    os << j.name << " "
        << j.age << " "
        << j.power << " "
        << j.saber.color << " "
        << j.saber.type;

    return os;
}

istream& operator>>(istream& is, Jedi& j) {

    int c, t;

    is >> j.name >> j.age >> j.power >> c >> t;

    j.saber.color = (Color)c;
    j.saber.type = (Type)t;

    return is;
}

ostream& operator<<(ostream& os, const JediCollection& col) {

    os << col.getNumJedi() << endl;

    for (int i = 0; i < col.getNumJedi(); i++) {

        os << col.getJedi(i) << endl;
    }

    return os;
}

istream& operator>>(istream& is, JediCollection& col) {

    int n;
    is >> n;

    for (int i = 0; i < n; i++) {

        Jedi j;
        is >> j;
        col.addJedi(j);
    }

    return is;
}

class JediIO {

public:

    static void saveToBinary(const JediCollection& collection, const char* fileName) {

        ofstream file(fileName, ios::binary);

        int n = collection.getNumJedi();

        file.write((char*)&n, sizeof(n));

        for (int i = 0; i < n; i++) {

            Jedi j = collection.getJedi(i);
            file.write((char*)&j, sizeof(Jedi));
        }

        file.close();
    }

    static JediCollection readFromBinary(const char* fileName) {

        JediCollection collection;

        ifstream file(fileName, ios::binary);

        int n;
        file.read((char*)&n, sizeof(n));

        for (int i = 0; i < n; i++) {

            Jedi j;
            file.read((char*)&j, sizeof(Jedi));
            collection.addJedi(j);
        }

        file.close();

        return collection;
    }

    static void saveToTxt(const JediCollection& collection, const char* fileName) {

        ofstream file(fileName);

        file << collection;

        file.close();
    }

    static JediCollection readFromTxt(const char* fileName) {

        JediCollection collection;

        ifstream file(fileName);

        file >> collection;

        file.close();

        return collection;
    }
};

int main() {

    JediCollection col;

    col.addJedi(Jedi("Luke", 25, 90, BLUE, SINGLEBLADED));
    col.addJedi(Jedi("Anakin", 30, 100, BLUE, SINGLEBLADED));
    col.addJedi(Jedi("Mace", 45, 95, PURPLE, SINGLEBLADED));

    col.print();

    JediData::sortByAge(col);

    cout << "After sorting:\n";

    col.print();

    JediIO::saveToTxt(col, "jedi.txt");

    JediCollection newCol = JediIO::readFromTxt("jedi.txt");

    cout << "Loaded from file:\n";

    newCol.print();
} 