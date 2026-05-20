#include <iostream>
#include <ostream>
#include<print>
#include<fstream>

enum class ColorSaber {
    RED,
    YELLOW,
    GREEN,
    BLUE,
    PURPLE
};

enum class Type {
    SINGLE_BLADED,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct LightSaber {
    ColorSaber color = ColorSaber::RED;
    Type type = Type::SINGLE_BLADED;

public:
    LightSaber() = default;

    // LightSaber(const ColorSaber color, const Type type) : color(color), type(type) {}
    LightSaber(const ColorSaber color, const Type type) {
        this->color = color;
        this->type = type;
    }
};

struct Jedi {
    char name[50 + 1] = "no name";
    unsigned int age = 0;
    unsigned int power = 0;
    LightSaber lightSaber;

public:
    void setJediAge(const unsigned int newAge) {
        this->age = newAge;
    }

    unsigned int getAge() const {
        return this->age;
    }

    char *getName() {
        return this->name;
    }

    unsigned int getPower() const {
        return this->power;
    }

    void setJediPower(const unsigned int newPower) {
        this->power = newPower;
    }

    ColorSaber getColor() const {
        return lightSaber.color;
    }

    Type getType() const {
        return lightSaber.type;
    }

    Jedi() = default;

    Jedi(const char *name, const unsigned age, const unsigned power, const LightSaber saber) {
        strcpy(this->name, name);
        this->name[50] = '\0';
        this->age = age;
        this->power = power;
        this->lightSaber = saber;
    }

    Jedi(const char *name, const unsigned age, const unsigned power, const ColorSaber color,
         const Type type) : lightSaber(color, type) {
        strcpy(this->name, name);
        this->age = age;
        this->power = power;
    }
};

class JediCollection {
    const int MAX_SIZE = 100;

private:
    Jedi *jedi = new Jedi[MAX_SIZE];
    int count = 0;

public:
    Jedi &getJedi(const unsigned int index) const {
        return jedi[index];
    }

    unsigned int getSize() const {
        return count;
    }

    void addJedi(const Jedi &newJedi) {
        if (count < MAX_SIZE) {
            jedi[count] = newJedi;
            count++;
            std::println("successfully added jedi");
            return;
        }
        std::println("out of jedi");
    }

    void removeJedi(const char *name) {
        for (int i = 0; i < count; i++) {
            if (strcmp(jedi[i].name, name) == 0) {
                for (int j = i; j < count - 1; j++) {
                    jedi[j] = jedi[j + 1];
                }
                count--;
            }
        }
        std::println("successfully removed jedi");
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            std::println("{} - {} ages - {} ", jedi[i].getName(), jedi[i].age, jedi[i].power);
        }
    }

    ~JediCollection() {
        delete[] jedi;
        jedi = nullptr;
        count = 0;
    }
};

class JediData {
public:
    static void sortByAge(const JediCollection &collection) {
        const unsigned int size = collection.getSize();
        for (int i = 1; i < size; i++) {
            Jedi currentEl = collection.getJedi(i);
            int currentInd = i - 1;

            while (currentInd >= 0 && currentEl.getAge() < collection.getJedi(currentInd).getAge()) {
                collection.getJedi(currentInd + 1) = collection.getJedi(currentInd);
                currentInd--;
            }

            collection.getJedi(currentInd + 1) = currentEl; // setAge;
        }
    }

    static void sortByPower(const JediCollection &collection) {
        const unsigned int size = collection.getSize();
        for (int i = 1; i < size; i++) {
            Jedi currentEl = collection.getJedi(i);
            int currentInd = i - 1;

            while (currentInd >= 0 && currentEl.getPower() < collection.getJedi(currentInd).getPower()) {
                collection.getJedi(currentInd + 1) = collection.getJedi(currentInd);
                currentInd--;
            }

            collection.getJedi(currentInd + 1) = currentEl; // setAge;
        }
    }

    static ColorSaber mostPopularSaberColor(const JediCollection &collection) {
        int countColors[5] = {0};

        const int size = (int) collection.getSize();
        for (int i = 0; i < size; i++) {
            countColors[(int) collection.getJedi(i).getColor()]++;
        }

        int maxIndex = 0;
        for (int i = 1; i < 5; i++) {
            if (countColors[i] > countColors[maxIndex]) {
                maxIndex = i;
            }
        }

        return (ColorSaber) maxIndex;
    }

    static Type mostPopularSaberType(const JediCollection &collection) {
        int countTypes[3] = {0};

        const int size = (int) collection.getSize();
        for (int i=0;i<size;i++) {
            countTypes[(int) collection.getJedi(i).getType()]++;
        }

        int maxIndex = 0;
        for (int i = 1; i < 3; i++) {
            if (countTypes[i] > countTypes[maxIndex]) {
                maxIndex = i;
            }
        }

        return (Type) maxIndex;
    }
};

class JediIO {
public:

};

int main() {
    const LightSaber saber1(ColorSaber::BLUE, Type::SINGLE_BLADED);
    const LightSaber saber2(ColorSaber::RED, Type::CROSSGUARD);
    const LightSaber saber3(ColorSaber::YELLOW, Type::DOUBLE_BLADED);
    const LightSaber saber4(ColorSaber::GREEN, Type::CROSSGUARD);
    const LightSaber saber5(ColorSaber::PURPLE, Type::SINGLE_BLADED);

    Jedi jedi1("Luke", 25, 90, saber1);
    Jedi jedi2("Yoda", 75, 75, saber2);
    Jedi jedi3("Harry", 27, 84, saber3);
    Jedi jedi4("Heart", 35, 57, saber4);
    Jedi jedi5("Jone", 23, 67, saber5);
    Jedi jedi6("Nick", 19, 67, saber3);

    JediCollection c;
    c.addJedi(jedi1);
    c.addJedi(jedi2);
    c.addJedi(jedi3);
    c.addJedi(jedi4);
    c.addJedi(jedi5);
    c.addJedi(jedi6);

    std::println("Jedi collection print: ");
    c.print();

    const JediData data;
    data.sortByAge(c);

    std::println("Jedi data sorted by age");
    c.print();

    std::cout << std::endl;

    std::println("Jedi data sorted by power");
    data.sortByPower(c);
    c.print();

    std::cout << std::endl;

    ColorSaber color = data.mostPopularSaberColor(c);
    std::cout << (int) color<<std::endl;

    Type type = data.mostPopularSaberType(c);
    std::cout << (int) type;

    return 0;
}
