#pragma once
#include "Vehicle.h"

class VehicleList 
{
private:
    Vehicle** slots;
    unsigned cap;
    unsigned count;

    void resize();
    void copyFrom(const VehicleList& other);
    void free();
    void moveFrom(VehicleList&& other) noexcept;
    static const int CAP_SIZE = 4;

public:
    explicit VehicleList(unsigned initialCapacity = 4);

    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);
    VehicleList(VehicleList&& other) noexcept;
    VehicleList& operator=(VehicleList&& other) noexcept;
    ~VehicleList();

    VehicleList& operator+=(const Vehicle& v);
    VehicleList& operator-=(const Registration& reg);

    unsigned operator()(const char* cityCode) const;

    Vehicle* operator[](unsigned index);
    const Vehicle* operator[](unsigned index) const;

    std::partial_ordering operator<=>(const VehicleList& other) const;
    bool operator==(const VehicleList& other) const;

    explicit operator bool() const;

    bool isFreeSlot(unsigned pos) const;
    bool isEmpty() const;
    unsigned capacity() const;
    unsigned size() const;
    Vehicle* find(const Registration& reg) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
};
