#pragma once
#include <iostream>
#include <string>

class CarPart {
private:
    unsigned int id;
    std::string manufacturer;
    std::string description;

public:
    CarPart() : id(1) {} 
    virtual ~CarPart() = default;


    unsigned int getId() const;
    std::string getManufacturer() const;
    std::string getDescription() const;

    void setId(unsigned int newId);
    void setManufacturer(const std::string& m);
    void setDescription(const std::string& d);

    virtual void print(std::ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const CarPart& cp);
};