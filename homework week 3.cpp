#include <cstring>
#include <iostream>
#include <fstream>

#include <cstring>
#include <iostream>
#include <fstream>
enum Color{
    RED,
    BLUE,
    GREEN,
    YELLOW,
    PURPLE
};

enum Type{
    SINGLEBLADED,
    DOUBLE_BLADED,
    CROSSGUARD
};

struct LightSaber{
    Color color;
    Type type;
};


struct Jedi{
    char name[50];
    int age;
    int power;
    LightSaber lightSaber;
    public:
    Jedi() = default;
    Jedi(const char* name, int age, int power, Color color, Type type){
        strncpy(this->name, name, 50);
        this->age = age;
        this->power = power;
        this->lightSaber.color = color;
        this->lightSaber.type = type;
    }
    Jedi(const char* name, int age, int power, LightSaber saber){
        strncpy(this->name, name, 50);
        this->age = age;
        this->power = power;
        this->lightSaber = saber;
    }
};

class JediCollection{
    int capacity;
    Jedi* jedi;
    int size_Array=0;
public:
    JediCollection(int capacity){
        this->capacity = capacity;
        jedi = new Jedi[capacity];
    }

    int getCapacity(){
        return capacity;
    }
    void addJedi(const Jedi& newJedi){
        jedi[size_Array] = newJedi;
        size_Array++;
    }
    int getJediAge(int i) const{
        return jedi[i].age;
    }
    int& setJediAge(int i, int age){
        return jedi[i].age = age;
    }
    int getJediPower(int i ) const{
        return jedi[i].power;
    }
    int& setJediPower(int i, int power){
        return jedi[i].power = power;
    }
    int getJediColor(int i) const{
        return jedi[i].lightSaber.color;
    }
    int getJediType(int i) const {
        return jedi[i].lightSaber.type;
    }

    void deleteJedi(const char* name){
        for(int i = 0; i < capacity; i++){
            if(strcmp(jedi[i].name, name) == 1){
                for(int j = i; j < capacity - 1; j++){
                    jedi[j] = jedi[j + 1];
                }
                break;
            }

        }
    }

    void print(){
        for(int i=0;i< capacity; i++){
            std::cout << "Name: " << jedi[i].name
            << ", Age: " << jedi[i].age
            << ", Power: " << jedi[i].power
            << ", LightSaber Color: " << jedi[i].lightSaber.color
            << ", LightSaber Type: " << jedi[i].lightSaber.type
            << std::endl;
        }
    }


    ~JediCollection(){
        delete[] jedi;
    }

};

class JediData{
    JediCollection collection;
    public:
    JediData(int capacity): collection(capacity) {};
    void sortByAge(JediCollection& collection){
        for(int i = 0; i < collection.getCapacity(); i++){
            for(int j = i; j < collection.getCapacity(); j++){
                if(collection.getJediAge(i) > collection.getJediAge(j)){
                    int temp = collection.getJediAge(i);
                    collection.setJediAge(i, collection.getJediAge(j));
                    collection.setJediAge(j, temp);
                }
            }
        }
        for(int i=0;i< collection.getCapacity(); i++){
            std::cout << "Name: " << collection.getJediAge(i) << std::endl;
        }
    }
    void sortByPower(JediCollection& collection){
        for(int i = 0; i < collection.getCapacity(); i++){
            for(int j = i; j < collection.getCapacity(); j++){
                if(collection.getJediPower(i) > collection.getJediPower(j)){
                    int temp = collection.getJediPower(i);
                    collection.setJediPower(i, collection.getJediPower(j));
                    collection.setJediPower(j, temp);
                }
            }
        }
        for(int i=0;i< collection.getCapacity(); i++){
            std::cout << "Name: " << collection.getJediPower(i) << std::endl;
        }
    }

    Color mostPopularSaberColor(JediCollection& collection) const{
        int colorCount[5] = {0};
        for(int i=0; i< collection.getCapacity(); i++){
            if(collection.getJediColor(i) >= 0 && collection.getJediColor(i) < 5){
                colorCount[collection.getJediColor(i)]++;
            }
        }
        int maxCount = 0;
        int colorIndex=-1;
        for(int i=0;i<5;i++){
            if(colorCount[i] > maxCount){
                maxCount = colorCount[i];
                colorIndex = i;
            }
        }
        if(colorIndex != -1){
            return static_cast<Color>(colorIndex);
        }
        return static_cast<Color>(0);
    }
    Type mostPopularSaberType(JediCollection& collection) const{
        int typeCount[3] = {0};
        for(int i=0; i< collection.getCapacity(); i++){
            if(collection.getJediType(i) >= 0 && collection.getJediType(i) < 3){
                typeCount[collection.getJediType(i)]++;
            }
        }
        int maxCount = 0;
        int typeIndex=-1;
        for(int i=0;i<3;i++){
            if(typeCount[i] > maxCount){
                maxCount = typeCount[i];
                typeIndex = i;
            }
        }
        if(typeIndex != -1){
            return static_cast<Type>(typeIndex);
        }
        return SINGLEBLADED;
    }
};

class JediIO{
public:

    static void saveToBinary(const JediCollection& collection, const char* fileName){
        std::ofstream ofs(fileName, std::ios::binary);
        saveToBinary(collection, ofs);
        ofs.close();
    }

    static JediCollection readFromBinary(const char* fileName){
        std::ifstream ifs(fileName, std::ios::binary);
        JediCollection result = readFromBinary(ifs);
        ifs.close();
        return result;
    }

    static void saveToTxt(const JediCollection& collection, const char* fileName){
        std::ofstream ofs(fileName);
        saveToTxt(collection, ofs);
        ofs.close();
    }

    static JediCollection readFromTxt(const char* fileName){
        std::ifstream ifs(fileName);
        JediCollection result = readFromTxt(ifs);
        ifs.close();
        return result;
    }

    static void saveToBinary(JediCollection& collection, std::ofstream& ofs){

        int capacity = collection.getCapacity();
        ofs.write((const char*)&capacity, sizeof(capacity));

        for(int i = 0; i < capacity; i++){
            Jedi j;
            j.age = collection.getJediAge(i);
            j.power = collection.getJediPower(i);
            j.lightSaber.color = (Color)collection.getJediColor(i);
            j.lightSaber.type = (Type)collection.getJediType(i);

            ofs.write((const char*)&j, sizeof(Jedi));
        }
    }

    static JediCollection readFromBinary(std::ifstream& ifs){

        int capacity;
        ifs.read((char*)&capacity, sizeof(capacity));

        JediCollection collection(capacity);

        for(int i = 0; i < capacity; i++){
            Jedi j;
            ifs.read((char*)&j, sizeof(Jedi));
            collection.addJedi(j);
        }

        return collection;
    }

    static void saveToTxt(JediCollection& collection, std::ofstream& ofs){

        int capacity = collection.getCapacity();
        ofs << capacity << std::endl;

        for(int i = 0; i < capacity; i++){
            ofs << collection.getJediAge(i) << " "
                << collection.getJediPower(i) << " "
                << collection.getJediColor(i) << " "
                << collection.getJediType(i)
                << std::endl;
        }
    }

    static JediCollection readFromTxt(std::ifstream& ifs){

        int capacity;
        ifs >> capacity;

        JediCollection collection(capacity);

        for(int i = 0; i < capacity; i++){
            int age, power, color, type;

            ifs >> age >> power >> color >> type;

            Jedi j;
            j.age = age;
            j.power = power;
            j.lightSaber.color = (Color)color;
            j.lightSaber.type = (Type)type;

            collection.addJedi(j);
        }

        return collection;
    }
};


class secret{
    char *task;
    char *password;
    int wrongPass=0;
public:
    secret() = default;
    secret(const char *_task, const char *_password){
        task = new char[strlen(_task) + 1];
        password = new char[strlen(_password) + 1];
        strcpy(task, _task);
        strcpy(password, _password);
    }
    char* getTask(const char*password){
        if(strcmp(this->password,password)!=0){
            wrongPass++;
            return nullptr;
        }
        else{
            wrongPass=0;
            return task;
        }
    }
    void setPassword(const char* newPassword, const char* oldPassword){
        if(!strcmp(this->password, oldPassword) && !wrongPass){
            strcpy(this->password, newPassword);
        }
        else{
            std::cout << "The password is the same or you haven't entered the correct password" << std::endl;
        }
    }
    void setTask(const char* newTask, const char* passwd){
        if(strcmp(this->password, passwd) == 0){
            strcpy(this->task, newTask);
        }
        else{
            std::cout << "You haven't entered the correct password" << std::endl;
        }
    }
    //няма нужда от допълнителна функция за увеливане на броя на грешните влизания
    ~secret(){
        delete[] task;
        delete[] password;
    }


};
enum Color{
    RED,
    GREEN,
    WHITE
};
Color stringToColor(const std::string& str){
    if(strcmp(str.c_str(), "RED") == 0) return static_cast<Color>(0);
    if(strcmp(str.c_str(), "WHITE") == 0) return static_cast<Color>(2);
    if(strcmp(str.c_str(), "GREEN") == 0) return static_cast<Color>(1);
}
enum Taste{
    BLUEBERRY,
    MANGO,
    QUEEN, 
    STRAWBERRY,
    KIWI
};
Taste stringToTaste(const std::string& str){
    if(strcmp(str.c_str(), "BLUEBERRY") == 0) return static_cast<Taste>(0);
    if(strcmp(str.c_str(), "MANGO") == 0) return static_cast<Taste>(1);
    if(strcmp(str.c_str(), "QUEEN") == 0) return static_cast<Taste>(2);
    if(strcmp(str.c_str(), "STRAWBERRY") == 0) return static_cast<Taste>(3);
    if(strcmp(str.c_str(), "KIWI") == 0) return static_cast<Taste>(4);
}
class Baloon{
    Color color;
    double price;
public:
    Baloon() = default;
    Baloon(Color _color, double _price){
        color = _color;
        price = _price;
    }
    void setColor(Color newColor){
        color = newColor;
    }
    void setPrice(double newPrice){
        price = newPrice;
    }
    Color getColor() const{
        return color;
    }
    double getPrice() const{
        return price;
    }
};

class Narga{
    Taste taste;
    double price;
    char* brand;
public:
    Narga() = default;
    Narga(Taste _taste, double _price, const char* _brand){
        taste = _taste;
        price = _price;
        brand = new char[strlen(_brand) + 1];
        strcpy(brand, _brand);
    }
    void setTaste(Taste newTaste){
        taste = newTaste;
    }
    void setPrice(double newPrice){
        price = newPrice;
    }
    void print() const{
        std::cout << "Taste: " << taste << ", Price: " << price << ", Brand: " << brand << std::endl;
    }
    void setBrand(const char* newBrand){
        strcpy(brand, newBrand);
    }
    Taste getTaste() const{
        return taste;
    }
    double getPrice() const{
        return price;
    }
    const char* getBrand() const{
        return brand;
    }

    ~Narga(){
        delete[] brand;
    }
    

};

class Alcohol{
    double price;
    char* brand;
public:
    Alcohol() = default;
    Alcohol(double _price, const char* _brand){
        price = _price;
        brand = new char[strlen(_brand) + 1];
        strcpy(brand, _brand);
    }
    void setPrice(double newPrice){
        price = newPrice;
    }
    void setBrand(const char* newBrand){
        strcpy(brand, newBrand);
    }
    double getPrice() const{
        return price;
    }
    const char* getBrand() const{
        return brand;
    }
    ~Alcohol(){
        delete[] brand;
    }
};

class NightClub{
    Baloon baloons[1024];
    Alcohol alcohols[512];
    Narga nargas[256];

    int baloonSize = 0;
    int alcoholSize = 0;
    int nargaSize = 0;
public:
    NightClub()= default;
    void addBaloon(){
        if(baloonSize < 1024){
            std::string input;
            double price;
            getline(std::cin, input, '-');
            std::cin >> price;
            baloons[baloonSize++] = Baloon(stringToColor(input), price);
        }
    }
    void addAlcohol(){
        if(alcoholSize < 512){
           std::string input;
            double price;
            getline(std::cin, input, '-');
            std::cin >> price;
            alcohols[alcoholSize++] = Alcohol(price, (char*)input.c_str());
        }
    }
    void addNarga(){
        if(nargaSize < 256){
            std::string inputBrand;
            std::string inputTaste;
            double price;
            getline(std::cin, inputBrand, '-');
            getline(std::cin, inputTaste, '-');
            std::cin >> price;
            nargas[nargaSize++] = Narga(stringToTaste(inputTaste), price, (char*)inputBrand.c_str());
        }
    }

    void removeBaloon(){
        if(baloonSize > 0){
            std::string input;
            getline(std::cin, input);
            for(int i = 0; i < baloonSize; i++){
                if(baloons[i].getColor() == stringToColor(input)){
                    for(int j = i; j < baloonSize - 1; j++){
                        baloons[j] = baloons[j + 1];
                    }
                    baloonSize--;
                    break;
                }
            }
        }


    }
    void removeAlcohol(){
        if(alcoholSize > 0){
            std::string input;
            getline(std::cin, input);
            for(int i = 0; i < alcoholSize; i++){
                if(strcmp(alcohols[i].getBrand(), input.c_str()) == 0){
                    for(int j = i; j < alcoholSize - 1; j++){
                        alcohols[j] = alcohols[j + 1];
                    }
                    alcoholSize--;
                    break;
                }
            }
        }
    }

    void removeNarga(){
        if(nargaSize > 0){
            std::string inputBrand;
            std::string inputTaste;
            getline(std::cin, inputBrand, '-');
            getline(std::cin, inputTaste, '-');
            for(int i = 0; i < nargaSize; i++){
                if(strcmp(nargas[i].getBrand(), inputBrand.c_str()) == 0 && nargas[i].getTaste() == stringToTaste(inputTaste)){
                    for(int j = i; j < nargaSize - 1; j++){
                        nargas[j] = nargas[j + 1];
                    }
                    nargaSize--;
                    break;
                }
            }
        }
    }

    bool isBaloonInStock(){
        std::string input;
        getline(std::cin, input);
        for(int i = 0; i < baloonSize; i++){
            if(baloons[i].getColor() == stringToColor(input)){
                return true;
            }
        }
        return false;
    }

    bool isAlcoholInStock(){
        std::string input;
        getline(std::cin, input);
        for(int i = 0; i < alcoholSize; i++){
            if(strcmp(alcohols[i].getBrand(), input.c_str()) == 0){
                return true;
            }
        }
        return false;
    }

    bool isNargaInStock(){
        std::string inputTaste;
        getline(std::cin, inputTaste, '-');
        for(int i = 0; i < nargaSize; i++){
            if(nargas[i].getTaste() == stringToTaste(inputTaste)){
                return true;
            }
        }
        return false;
    }

double calculateBill(const char* fileName){

    std::ifstream file(fileName);

    if(!file){
        std::cout << "File error\n";
        return 0;
    }

    double total = 0;

    std::string type;

    while(file >> type){

        if(type == "BALLOON"){

            std::string colorStr;
            int quantity;

            file >> colorStr >> quantity;

            Color c = stringToColor(colorStr);

            for(int i = 0; i < baloonSize; i++){
                if(baloons[i].getColor() == c){
                    total += baloons[i].getPrice() * quantity;
                }
            }
        }

        else if(type == "ALCOHOL"){

            std::string brand;
            int quantity;

            file >> brand >> quantity;

            for(int i = 0; i < alcoholSize; i++){
                if(strcmp(alcohols[i].getBrand(), brand.c_str()) == 0){
                    total += alcohols[i].getPrice() * quantity;
                }
            }
        }

        else if(type == "NARGA"){

            std::string tasteStr;
            std::string brand;
            int quantity;

            file >> tasteStr >> brand >> quantity;

            Taste t = stringToTaste(tasteStr);

            for(int i = 0; i < nargaSize; i++){
                if(nargas[i].getTaste() == t &&
                   strcmp(nargas[i].getBrand(), brand.c_str()) == 0){
                    total += nargas[i].getPrice() * quantity;
                }
            }
        }
    }

    file.close();
    return total;
}

};

struct Client{
    char* name;
    char* fileName;

};

void printBill(Client client, NightClub& club){
    double total = club.calculateBill(client.fileName);
    std::cout << "Client: " << client.name << ", Total Bill: " << total << std::endl;
}