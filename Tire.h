#pragma once
#include "CarPart.h"

class Tire : public CarPart {
private:
    int width;
    int profile;
    int rimSize;

public:
    Tire() : width(155), profile(30), rimSize(13) {}

    int getWidth_() const;
    int getProfile_() const;
    int getRimSize() const;

    void setWidth(int w);
    void setProfile(int p);
    void setRimSize(int r);

    void print(std::ostream& os) const override;
};