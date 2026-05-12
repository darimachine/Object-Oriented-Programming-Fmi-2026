
#pragma once
#include "CarPart.h"

class Engine : public CarPart {
private:
    int horsepower;
public:
    void setHorsepower(int hp);
    int getHorsepower() const;
    void print(std::ostream& os) const override;
};