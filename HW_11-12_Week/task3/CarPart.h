#pragma once
#include <string>
class CarPart
{
protected:
    unsigned id;
    std::string manufacturer;
    std::string description;
public:
    CarPart(unsigned id, std::string manufacturer, std::string description);
    virtual ~CarPart() = default;
    virtual void printExtended(std::ostream& os) const = 0;
    friend std::ostream& operator<<(std::ostream& os, const CarPart& cp);
};

