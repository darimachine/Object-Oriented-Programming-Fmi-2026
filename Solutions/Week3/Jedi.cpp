#include <iostream>
#include <cstring>
#include <fstream>
#include <print>

constexpr int MAX_NAME = 51;
constexpr int MAX_JEDI = 100;

enum class Color {
    RED,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE
};

enum class Type {
    SINGLEBLADED,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct Lightsaber {
    Color color;
    Type type;
};

struct Jedi {
    char name[MAX_NAME];
    int age;
    int power;
    Lightsaber lightsaber;

    Jedi() : age(0), power(0) {
        name[0] = '\0';
        lightsaber.color = Color::BLUE;
        lightsaber.type = Type::CROSSGUARD;
    }

    Jedi(const char *name_, int age_, int power_, const Lightsaber &lightsaber_) : age(age_), power(power_),
        lightsaber(lightsaber_) {
        strcpy(name, name_);
    }

    Jedi(const char *name_, int age_, int power_, Color color_, Type type_) : age(age_), power(power_) {
        strcpy(name, name_);
        lightsaber.color = color_;
        lightsaber.type = type_;
    }
};

class JediCollection {
public:
    Jedi jedis[MAX_JEDI];
    int count = 0;

    JediCollection() {
        count = 0;
    }

    void addJedi(const Jedi &jedi) {
        if (count >= MAX_JEDI) {
            return;
        }

        jedis[count++] = jedi;
    }

    void removeJedi(const char *name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(jedis[i].name, name) == 0) {
                for (int j = i; j < count - 1; j++) {
                    jedis[j] = jedis[j + 1];
                }
                count--;
                break;
            }
        }
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            std::cout << jedis[i].name << " " << jedis[i].age << " " << jedis[i].power << " " << static_cast<int>(jedis[
                i].lightsaber.color) << " " << static_cast<int>(jedis[i].lightsaber.type) << '\n';
        }
    }
};

class JediData {
public:
    static void sortByAge(JediCollection &collection) {
        for (int i = 0; i < collection.count; i++) {
            for (int j = 0; j < collection.count; j++) {
                if (collection.jedis[i].age > collection.jedis[j].age) {
                    Jedi temp = collection.jedis[i];
                    collection.jedis[i] = collection.jedis[j];
                    collection.jedis[j] = temp;
                }
            }
        }
    }

    static void sortByPower(JediCollection &collection) {
        for (int i = 0; i < collection.count; i++) {
            for (int j = 0; j < collection.count; j++) {
                if (collection.jedis[i].power > collection.jedis[j].power) {
                    Jedi temp = collection.jedis[i];
                    collection.jedis[i] = collection.jedis[j];
                    collection.jedis[j] = temp;
                }
            }
        }
    }

    static Color mostPopularColor(const JediCollection &collection) {
        int counter[5] = {0};
        for (int i = 0; i < collection.count; i++) {
            counter[static_cast<int>(collection.jedis[i].lightsaber.color)]++;
        }
        int maxIndex = 0;
        for (int i = 1; i < 5; i++) {
            if (counter[i] > counter[maxIndex]) maxIndex = i;
        }
        return static_cast<Color>(maxIndex);
    }

    static Type mostPopularSaberType(const JediCollection &collection) {
        int counter[3] = {0};
        for (int i = 0; i < collection.count; i++) {
            counter[static_cast<int>(collection.jedis[i].lightsaber.type)]++;
        }
        int maxIndex = 0;
        for (int i = 1; i < 3; i++) {
            if (counter[i] > counter[maxIndex]) maxIndex = i;
        }
        return static_cast<Type>(maxIndex);
    }
};

class JediIO {
public:
    static void saveToBinary(const JediCollection &collection, const char *fileName) {
        std::ofstream file(fileName, std::ios::binary);
        int count = collection.count;
        file.write((char *) &count, sizeof(count));
        for (int i = 0; i < collection.count; i++) {
            file.write((char *) &collection.jedis[i].age, sizeof(collection.jedis[i].age));
            file.write((char *) &collection.jedis[i].power, sizeof(collection.jedis[i].power));
            file.write(collection.jedis[i].name, sizeof(collection.jedis[i].name));

            int colorInt = static_cast<int>(collection.jedis[i].lightsaber.color);
            int typeInt = static_cast<int>(collection.jedis[i].lightsaber.type);
            file.write((char *) &colorInt, sizeof(colorInt));
            file.write((char *) &typeInt, sizeof(typeInt));
        }
    }

    static JediCollection readFromBinary(const char *fileName) {
        std::ifstream file(fileName, std::ios::binary);
        JediCollection result;
        int count;
        file.read((char *) &count, sizeof(count));
        result.count = count;

        for (int i = 0; i < count; i++) {
            file.read((char *) &result.jedis[i].age, sizeof(result.jedis[i].age));
            file.read((char *) &result.jedis[i].power, sizeof(result.jedis[i].power));
            file.read(result.jedis[i].name, sizeof(result.jedis[i].name));

            int colorInt, typeInt;
            file.read((char *) &colorInt, sizeof(colorInt));
            file.read((char *) &typeInt, sizeof(typeInt));

            result.jedis[i].lightsaber.color = static_cast<Color>(colorInt);
            result.jedis[i].lightsaber.type = static_cast<Type>(typeInt);
        }

        return result;
    }

    static void saveToTxt(const JediCollection &collection, const char *fileName) {
        std::ofstream file(fileName);
        file << collection.count << '\n';
        for (int i = 0; i < collection.count; i++) {
            file << collection.jedis[i].name << " "
                    << collection.jedis[i].age << " "
                    << collection.jedis[i].power << " "
                    << static_cast<int>(collection.jedis[i].lightsaber.color) << " "
                    << static_cast<int>(collection.jedis[i].lightsaber.type) << '\n';
        }
    }

    static JediCollection readFromTxt(const char *fileName) {
        std::ifstream file(fileName);
        JediCollection result;
        int count;
        file >> count;
        result.count = count;

        for (int i = 0; i < count; i++) {
            int colorInt, typeInt;
            file >> result.jedis[i].name
                    >> result.jedis[i].age
                    >> result.jedis[i].power
                    >> colorInt
                    >> typeInt;

            result.jedis[i].lightsaber.color = static_cast<Color>(colorInt);
            result.jedis[i].lightsaber.type = static_cast<Type>(typeInt);
        }

        return result;
    }
};
