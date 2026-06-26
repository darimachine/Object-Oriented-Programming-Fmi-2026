#pragma once
#include "CarPart.h"

class Tires : public CarPart {
int width;
int profile;
int diameter;

public:
Tires(unsigned int id, std::string name, std::string desc, int w, int p, int r);

void printInfo(std::ostream& os) const override;
};
