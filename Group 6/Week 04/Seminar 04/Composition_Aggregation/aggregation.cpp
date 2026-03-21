#include <iostream>

using std::cout;

class Car {
private:
    int maxSpeed;

public:
    explicit Car(int maxSpeed) : maxSpeed(maxSpeed) {}

    void print() const {
        cout << "Car max speed: " << maxSpeed << '\n';
    }
};

class Driver {
private:
    int experience;
    Car* car = nullptr; // aggregation, the Car exists independently of the Driver,
                        // the Driver is just "using" the Car

public:
    Driver(int experience, Car* car) : experience(experience), car(car) {}

    void print() const {
        cout << "Driver experience: " << experience << '\n';
        if (car != nullptr) {
            car->print();
        }
    }
};

int main() {
    Car c(220);
    
    {
        Driver firstDriver(5, &c);
        firstDriver.print();
    } // firstDriver's destructor is called here

    // the Car still lives independently of the Driver whose destructor was called
    Driver secondDriver(10, &c); // another driver starts using that same car
    secondDriver.print();
}
