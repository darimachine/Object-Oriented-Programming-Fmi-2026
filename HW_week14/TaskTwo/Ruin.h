#pragma once
#include <string>
#include "Coords.h"
#include <memory>
#include "Landmark.h"

class Ruin : public Landmark
{
private:
    std::string civilization;
public:
    Ruin(const std::string& name, Coords coords, int threat, const std::string& civilization);
    std::string getType() const override;
    void print() const override;
    std::unique_ptr<Landmark> clone() const override;
};

