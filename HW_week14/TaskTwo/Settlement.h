#pragma once
#include "Coords.h"
#include <string>
#include <memory>
#include "Landmark.h"

class Settlement : public Landmark
{
private:
    int population;
public:
    Settlement(const std::string& name, Coords coords, int threat, int population);
    std::string getType() const override;
    void print() const override;
    std::unique_ptr<Landmark> clone() const override;
};

