
#include <iostream>
#include <crtdbg.h>
using namespace std;
class Car {
public:
    string serialNumber;
    Car(string sN) : serialNumber(std::move(sN)) {}
    //Car(const string& sN) : serialNumber(std::move(sN))
    //Car(string& sN) : serialNumber(std::move(sN))
    //Car(string&& sN) : serialNumber(std::move(sN)) {}
    void print() const {
        std::cout << serialNumber << std::endl;
    }
};

int main() {
    string number = "AB3115ES";
    Car p1(number);
    Car p2(std::move(number));

    std::cout << "Number: " << number << std::endl;
    std::cout << "p1: "; p1.print();
    std::cout << "p2: "; p2.print();
    return 0;
}
