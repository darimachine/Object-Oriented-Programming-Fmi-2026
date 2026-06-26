#pragma once
#include "Tire.h"
#include "CarPart.h"
#include <stdexcept>
#include <string>

class Engine : public CarPart
{
    int hp;
public:
    Engine(unsigned id, std::string manufacturer, std::string description, int hp);
    void printExtended(std::ostream& os) const override;
};

