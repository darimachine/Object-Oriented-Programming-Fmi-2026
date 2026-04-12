#include <iostream>

// Class with implicit conversion constructor
class Distance {
private:
    double meters;

public:
    Distance(double m) : meters(m) {}

    double getMeters() const {
        return meters;
    }
};

// Class with explicit conversion constructor
class ExplicitDistance {
private:
    double meters;

public:
    // the explicit keyword 
    explicit ExplicitDistance(double m) : meters(m) {}

    double getMeters() const {
        return meters;
    }
};

void printDistance(const Distance& distance) {
    std::cout << distance.getMeters() << std::endl;
}

void printExplicitDistance(const ExplicitDistance& explDistance) {
    std::cout << explDistance.getMeters() << std::endl;
}

int main() {
    // Implicit conversion allowed
    Distance d1 = 10; // Works
    std::cout << d1.getMeters() << std::endl;

    // ExplicitDistance d2 = 2.5; // Error! Explicit constructor prevents implicit conversion
    ExplicitDistance explicitDistance(2.5);  // only with constructor or explicitly casting

    std::cout << explicitDistance.getMeters() << std::endl;

    ExplicitDistance castDistance = (ExplicitDistance)2.5; // Works
    std::cout << castDistance.getMeters() << std::endl;

    printDistance(15); // this will actually call the conversion constructor Distance(int)

    // printExplicitDistance(15); // error!
    printExplicitDistance(ExplicitDistance(15)); // explicitly calling the constructor works

    return 0;
}
