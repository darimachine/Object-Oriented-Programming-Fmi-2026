#pragma once
#include  "Registration.h"

constexpr  int MIN_PROD_Y = 2000;
constexpr  int MIN_HORSE_P = 60;
class Vehicle
{
    private:
    Registration regNum;
    char * description = nullptr;
    int productionYear;
    int horsePowers;

    public:
        Vehicle() = delete;
        Vehicle(const Registration&,const char*, int, int);
        void setDescription(const char*);
        void setProdY(int);
        void setHorsePower(int);
        ~Vehicle();

        friend  std::ostream& operator<<(std::ostream&, const Vehicle&);
        friend bool operator==(const Vehicle&, const Vehicle&);
        std::strong_ordering operator<=>(const Vehicle &) const;
        const Registration& getRegistration() const;
};


