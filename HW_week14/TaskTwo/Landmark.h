#pragma once
#include <string>
#include "Coords.h"
#include <memory>
class Landmark
{
protected:
    std::string name;
    Coords coords;
    int threat;
public:
    Landmark(const std::string& name, Coords coords, int threat);
    virtual ~Landmark() = default;
    virtual std::string getType() const = 0;
    virtual void print() const = 0;
    virtual std::unique_ptr<Landmark> clone() const = 0;
    const std::string& getName() const;
    Coords getCoords() const;
    int getThreat() const;
};

