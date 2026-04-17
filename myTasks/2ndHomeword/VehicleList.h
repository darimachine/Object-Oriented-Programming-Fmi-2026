#pragma once
#include  "Vehicle.h"
#include  <compare>
class VehicleList
{
    private:
        Vehicle ** vechileLists = nullptr;
        size_t capacity;
        size_t vechileCount;

        void resize(size_t);
        void copyFrom(const VehicleList&);
        void moveFrom(VehicleList&&) noexcept;
        void free();

    public:
       explicit VehicleList(size_t);

        VehicleList& operator+=(const Vehicle&);
        VehicleList& operator-=(const Vehicle&);
        friend std::ostream& operator<<(std::ostream&, const VehicleList&);
        friend bool operator==(const VehicleList&, const VehicleList&) ;
        std::strong_ordering operator <=>(const VehicleList&);
        int operator()(const char*) const;
        operator bool() const;
        bool isFreeSlot(size_t ) const;
        bool isEmpty() const;
        int getCapacity() const;
        int getSize() const;
        Vehicle * find(const Registration&) const;

        ~VehicleList();
    
        VehicleList(const VehicleList&);
        VehicleList& operator=(const VehicleList&);

        VehicleList(VehicleList&&);
        VehicleList& operator=(VehicleList&&);
};


