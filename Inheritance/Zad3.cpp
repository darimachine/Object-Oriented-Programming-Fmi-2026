#include <iostream>
#include <string>
#include <stdexcept>

class CarPart {
protected:
    unsigned id{};
    std::string manufacturer;
    std::string description;

    std::ostream& printBase(std::ostream& os) const {
        return os << "(" << id << ") by " << manufacturer << " - " << description;
    }

public:
    CarPart(unsigned id, const std::string& manufacturer, const std::string& description) : id(id), manufacturer(manufacturer), description(description) {
        if (id == 0) {
            throw std::invalid_argument("id needs to be > 0");
        }
    }

};

class Tire : public CarPart {
    int width{};
    int profile{};
    int rimSize{};

    static void validate(int variable, int min, int max, const char* name) {
        if (variable < min || variable > max) {
            throw std::out_of_range(std::string(name) + " is out of bounds");
        }
    }

public:
    Tire(unsigned id, const std::string& manufacturer, const std::string& description, int width, int profile, int rimSize) : CarPart(id, manufacturer, description), width(width), profile(profile), rimSize(rimSize) {
        validate(width, 155, 365, "Width");
        validate(profile, 30, 80, "Profile");
        validate(rimSize, 13, 21, "Rim size");
    }

    friend std::ostream& operator<<(std::ostream& os, const Tire& t) {
        t.printBase(os) << " - " << t.width << "/" << t.profile << "R" << t.rimSize;
        return os;
    }

};

class Engine : public CarPart {
    int horsepower{};

public:
    Engine(unsigned id, const std::string& manufacturer, const std::string& description, int horsepower) : CarPart(id, manufacturer, description), horsepower(horsepower) {}

    friend std::ostream& operator<<(std::ostream& os, const Engine& e) {
        e.printBase(os) << " - " << e.horsepower << " hp";
        return os;
    }

};

class Accumulator : public CarPart {
    double ampHours{};
    std::string accID;

public:
    Accumulator(unsigned id, const std::string& manufacturer, const std::string& description, double ampHours, const std::string& accID) : CarPart(id, manufacturer, description), ampHours(ampHours), accID(accID) {
    }

    friend std::ostream& operator<<(std::ostream& os, const Accumulator& a) {
        a.printBase(os) << " - " << a.ampHours << " Ah";
        return os;
    }

};