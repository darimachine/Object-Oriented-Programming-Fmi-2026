#include <cstring>
#include <iostream>
#include <print>
#include <fstream>

// NOTE new elements should always be added before the COUNT state and UNKNOW should always be first with value -1
enum class LightSaberColour {

    UNKNOWN = -1, RED, YELLOW, GREEN, BLUE, PURPLE, COUNT
};

// NOTE new elements should always be added before the COUNT state and UNKNOW should always be first with value -1
enum class LightSaberType {

    UNKNOWN = -1, SINGLE_BLADED, DOUBLE_BLADED, CROSSGUARD, COUNT
};

// Function for LightSaberColour
const char* lightSaberColourToString(const LightSaberColour &colour) {

    switch (colour) {
        case LightSaberColour::RED:    return "Red";
        case LightSaberColour::YELLOW: return "Yellow";
        case LightSaberColour::GREEN:  return "Green";
        case LightSaberColour::BLUE:   return "Blue";
        case LightSaberColour::PURPLE: return "Purple";
        default:                       return "Unknown";
    }
}

// Function for LightSaberType
const char* lightSaberTypeToString(const LightSaberType &type) {

    switch (type) {
        case LightSaberType::SINGLE_BLADED: return "Single-Bladed";
        case LightSaberType::DOUBLE_BLADED: return "Double-Bladed";
        case LightSaberType::CROSSGUARD:    return "Crossguard";
        default:                            return "Unknown";
    }
}

struct LightSaber {

private:
    LightSaberType type;
    LightSaberColour colour;

public:

    LightSaber() = default;

    LightSaber(LightSaberType type, LightSaberColour colour) : type(type), colour(colour){}

    LightSaberColour getLightSaberColour() const {
        return this -> colour;
    }

    LightSaberType getLightSaberType() const {
        return this -> type;
    }

    void printLightSaber(std::ostream &output) {

        output << lightSaberColourToString(this -> colour) << " " << lightSaberTypeToString(this -> type) << " lightsaber";
    }
};

struct Jedi {

public:
    static constexpr short NAME_LENGTH = 50;

private:
    char name[NAME_LENGTH + 1];
    int age = -1;
    int power = -1;
    LightSaber lightSaber = LightSaber(LightSaberType::UNKNOWN, LightSaberColour::UNKNOWN);

public:

    // NOTE constructors

    Jedi() = default;

    Jedi(const char* name, const int age, const int power, const LightSaber lightSaber) : age(age), power(power),
    lightSaber(lightSaber) {

        setName(name);
    }

    Jedi(const char* name, const int age, const int power, const LightSaberType &lightSaberType,
        const LightSaberColour &lightSaberColour) : Jedi(name, age, power,
            LightSaber(lightSaberType, lightSaberColour)) {}

    // NOTE setters
    void setName(const char* name) {

        if (name == nullptr) return;
        if (strlen(name) > NAME_LENGTH) return;

        strcpy((*this).name, name);

        this->name[50] = '\0';
    }

    // NOTE getters

    const char* getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    int getPower() const {
        return power;
    }

    LightSaber getLightSaber() const {
        return lightSaber;
    }

    void printJediInformation(std::ostream &output) const {

        output << getName() << ", ";
        std::print(output, "{}, {}, ", getAge(), getPower());
        getLightSaber().printLightSaber(output);
    }
};

class JediCollection {

private:
    Jedi jedis[100];
    int countOfJedis = 0;

public:

    JediCollection() = default;

    void addJedi(const Jedi &jedi) {

        jedis[countOfJedis++] = jedi;
    }

    void removeJedi(const char* name) {

        if (strlen(name) > Jedi::NAME_LENGTH) return;

        for (int i = 0; i < countOfJedis; i++) {

            if (strcmp(jedis[i].getName(), name) == 0) {

                countOfJedis--;
                for (int j = i; j < countOfJedis; j++) {
                    std::swap(jedis[j], jedis[j + 1]);
                }
            }
        }
    }

    void printJediCollection(std::ostream &output) const {

        for (int i = 0; i < countOfJedis; i++) {

            jedis[i].printJediInformation(output);
            output << std::endl;
        }

        output << std::endl;
    }

    // NOTE getters

    int getCountOfJedis() const {
        return countOfJedis;
    }

    Jedi* getJedis() {
        return jedis;
    }

    void getJedisArrCopy(Jedi* jedisCopy, int size) const {

        for (int i = 0 ; i < size; i++) {

            jedisCopy[i] = jedis[i];
        }
    }

};

class JediData {

public:

    static int getAgeFromJedi(const Jedi &jedi) {
        return jedi.getAge();
    }

    static int getPowerFromJedi(const Jedi &jedi) {
        return jedi.getPower();
    }

    static bool compareParametersAscending(const int jediParameter, const int minJediParameter) {

        return jediParameter < minJediParameter;
    }

    static bool compareParametersDescending(const int jediParameter, const int minJediParameter) {

        return jediParameter > minJediParameter;
    }

    static void selectionSort(JediCollection &jediCollection, int (*getter)(const Jedi &jedi),
        bool (*compareRule)(const int jediParameter, const int minJediParameter)) {

        Jedi* jedis = jediCollection.getJedis();
        int countOfJedis = jediCollection.getCountOfJedis();

        for (int i = 0; i < countOfJedis - 1; i++) {

            int minJediIndex = i;
            int minJediParameter = getter(jedis[i]);

            for (int j = i + 1; j < countOfJedis; j++) {

                if (compareRule(getter(jedis[j]), minJediParameter)) {

                    minJediIndex = j;
                    minJediParameter = getter(jedis[j]);
                }
            }

            if (minJediIndex != i) {

                std::swap(jedis[minJediIndex], jedis[i]);
            }
        }

    }

    static void sortByAge(JediCollection &collection) {

        JediData::selectionSort(collection, JediData::getAgeFromJedi, JediData::compareParametersAscending);
    }

    static void sortByPower(JediCollection &collection) {

        JediData::selectionSort(collection, JediData::getPowerFromJedi, JediData::compareParametersAscending);
    }

    static LightSaberColour mostPopularSaberColour(JediCollection &collection) {

        const Jedi* jedis = collection.getJedis();
        const int countOfJedis = collection.getCountOfJedis();

        constexpr int countOfLightSaberColours = static_cast<int>(LightSaberColour::COUNT);

        int occurrenceColour[countOfLightSaberColours] = {0};

        for (int i = 0; i < countOfJedis; i++) {

            // extracting the index of the current lightsaber colour
            int lightSaberColourIndex = static_cast<int>(jedis[i].getLightSaber().getLightSaberColour());

            // if we find an UNKNOWN value we skip it
            if (lightSaberColourIndex < 0) continue;

            occurrenceColour[lightSaberColourIndex]++;
        }

        int maxLightSaberColourIndex = -1;
        int maxCountOfOccurrence = -1;

        for (int i = 0; i < countOfLightSaberColours; i++) {

            if (occurrenceColour[i] > maxCountOfOccurrence) {

                maxCountOfOccurrence = occurrenceColour[i];
                maxLightSaberColourIndex = i;
            }
        }

        // if none of the colours have been occurred then we want the function to return the UNKNOWN value
        if (maxCountOfOccurrence == 0) maxLightSaberColourIndex = -1;

        return static_cast<LightSaberColour>(maxLightSaberColourIndex);
    }

    static LightSaberType mostPopularSaberType(JediCollection &collection) {

        const Jedi* jedis = collection.getJedis();
        const int countOfJedis = collection.getCountOfJedis();

        constexpr int countOfLightSaberTypes = static_cast<int>(LightSaberType::COUNT);

        int occurrenceType[countOfLightSaberTypes] = {0};

        for (int i = 0; i < countOfJedis; i++) {

            // extracting the index of the current lightsaber type
            int lightSaberTypeIndex = static_cast<int>(jedis[i].getLightSaber().getLightSaberType());

            // if we find an UNKNOWN value we skip it
            if (lightSaberTypeIndex < 0) continue;

            occurrenceType[lightSaberTypeIndex]++;
        }

        int maxLightSaberTypeIndex = -1;
        int maxCountOfOccurrence = -1;

        for (int i = 0; i < countOfLightSaberTypes; i++) {

            if (occurrenceType[i] > maxCountOfOccurrence) {

                maxCountOfOccurrence = occurrenceType[i];
                maxLightSaberTypeIndex = i;
            }
        }

        // if none of the types have been occurred then we want the function to return the UNKNOWN value
        if (maxCountOfOccurrence == 0) maxLightSaberTypeIndex = -1;

        return static_cast<LightSaberType>(maxLightSaberTypeIndex);
    }

};

class JediIO {

public:

    static void saveToBinary(const JediCollection &collection, const char* fileName) {

        const int countOfJedis = collection.getCountOfJedis();

        std::ofstream saveFile(fileName, std::ios::binary);

        if (!saveFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
            return;
        }

        saveFile.write(reinterpret_cast<const char *>(&collection), sizeof(collection));

        saveFile.close();
    }

    static void saveToTxt(const JediCollection &collection, const char* fileName) {

        const int countOfJedis = collection.getCountOfJedis();

        Jedi jedis[countOfJedis];
        collection.getJedisArrCopy(jedis, countOfJedis);

        std::ofstream saveFile(fileName);

        if (!saveFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
            return;
        }

        saveFile << countOfJedis << std::endl;

        for (int i = 0; i < countOfJedis; i++) {

            Jedi currJedi = jedis[i];

            const int currLightSaberTypeID = static_cast<int>(currJedi.getLightSaber().getLightSaberType());
            const int currLightSaberColourID = static_cast<int>(currJedi.getLightSaber().getLightSaberColour());

            saveFile << currJedi.getName() << "," << currJedi.getAge() << " " << currJedi.getPower() <<
                " " << currLightSaberTypeID << " " << currLightSaberColourID << std::endl;
        }

        saveFile.close();
    }

    static JediCollection readFromBinary(const char* fileName) {

        std::ifstream readFile(fileName, std::ios::binary);

        if (!readFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
            return JediCollection();
        }

        JediCollection collection = JediCollection();

        readFile.read(reinterpret_cast<char*>(&collection), sizeof(JediCollection));

        readFile.close();

        return collection;
    }

    static JediCollection readFromTxt(const char* fileName) {

        std::ifstream readFile(fileName);

        if (!readFile.is_open()) {
            std::cout << "File couldn't open" << std::endl;
            return JediCollection();
        }

        int countOfJedis = -1;
        readFile >> countOfJedis;
        readFile.ignore();

        JediCollection collection = JediCollection();

        for (int i = 0 ; i < countOfJedis; i++) {

            char name[Jedi::NAME_LENGTH] = {'\0'};

            int age;
            int power;
            int lightSaberColourID;
            int lightSaberTypeID;

            readFile.getline(name, Jedi::NAME_LENGTH + 1, ',');
            readFile >> age >> power >> lightSaberTypeID >> lightSaberColourID;

            readFile.ignore();

            collection.addJedi(Jedi(name, age, power, LightSaber(static_cast<LightSaberType>(lightSaberTypeID), static_cast<LightSaberColour>(lightSaberColourID))));
        }

        readFile.close();

        return collection;
    }
};

int main() {

    JediCollection jedis;

    Jedi jediLuke = Jedi("Luke", 25, 87, LightSaberType::SINGLE_BLADED, LightSaberColour::BLUE);
    Jedi jediStela = Jedi("Stela", 22, 65, LightSaberType::CROSSGUARD, LightSaberColour::PURPLE);
    Jedi jediRocky = Jedi("A$AP Rocky", 35, 999, LightSaberType::DOUBLE_BLADED, LightSaberColour::YELLOW);

    Jedi jedi1 = Jedi("Luke1", 25, 87, LightSaberType::DOUBLE_BLADED, LightSaberColour::BLUE);
    Jedi jedi2 = Jedi("Luke2", 12, 55, LightSaberType::SINGLE_BLADED, LightSaberColour::RED);
    Jedi jedi3 = Jedi("Luke3", 5, 34, LightSaberType::SINGLE_BLADED, LightSaberColour::GREEN);
    Jedi jedi4 = Jedi("Luke4", 37, 88, LightSaberType::DOUBLE_BLADED, LightSaberColour::BLUE);
    Jedi jedi5 = Jedi("Luke5", 49, 92, LightSaberType::SINGLE_BLADED, LightSaberColour::YELLOW);
    Jedi jedi6 = Jedi("Luke6", 41, 71, LightSaberType::CROSSGUARD, LightSaberColour::PURPLE);

    jedis.addJedi(jedi1);
    jedis.addJedi(jedi2);
    jedis.addJedi(jedi3);
    jedis.addJedi(jedi4);
    jedis.addJedi(jedi5);
    jedis.addJedi(jedi6);

    std::cout << "Initial collection of jedis: " << std::endl;
    jedis.printJediCollection(std::cout);

    const char* jediToRemove = "Luke";
    jedis.removeJedi(jediToRemove);

    std::cout << "Collection after removing " << jediToRemove << ": " << std::endl;
    jedis.printJediCollection(std::cout);

    JediData::selectionSort(jedis, JediData::getAgeFromJedi, JediData::compareParametersAscending);

    std::cout << "Collection after sorting by age ascending: " << std::endl;
    jedis.printJediCollection(std::cout);

    JediData::selectionSort(jedis, JediData::getPowerFromJedi, JediData::compareParametersDescending);

    std::cout << "Collection after sorting by power descending: " << std::endl;
    jedis.printJediCollection(std::cout);

    std::cout << "Most popular colour amongst all the lightsabers:" << std::endl;
    std::cout << lightSaberColourToString(JediData::mostPopularSaberColour(jedis)) << std::endl;
    std::cout << std::endl;

    std::cout << "Most popular type amongst all the lightsabers:" << std::endl;
    std::cout << lightSaberTypeToString(JediData::mostPopularSaberType(jedis)) << std::endl;
    std::cout << std::endl;

    std::cout << "Printing the collection into a file" << std::endl;
    std::ofstream fileOutput("fileOutput");
    jedis.printJediCollection(fileOutput);

    std::cout << "Creating a text file for current collection." << std::endl;
    JediIO::saveToTxt(jedis, "JedisSaveTXT");

    std::cout << "Reading from the newly created file." << std::endl;
    JediCollection txtFileSaveCollection = JediIO::readFromTxt("JedisSaveTXT");

    std::cout << "Printing the collection from the read file:" << std::endl;
    txtFileSaveCollection.printJediCollection(std::cout);

    std::cout << "Creating a binary file for current collection." << std::endl;
    JediIO::saveToBinary(jedis, "JedisSaveBIN");

    std::cout << "Reading from the newly created file." << std::endl;
    JediCollection binFileSaveCollection = JediIO::readFromBinary("JedisSaveBIN");

    std::cout << "Printing the collection from the read file:" << std::endl;
    binFileSaveCollection.printJediCollection(std::cout);

    return 0;
}
