#pragma once
#include "Vehicle.h"
#include <iostream>
#include <compare>

class VehicleList {
private:
    Vehicle** slots{};
    unsigned cap{};
    unsigned count{};

    void free();
    void copyFrom(const VehicleList& other);
    void resize();

public:
    explicit VehicleList(unsigned capacity);

    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);
    ~VehicleList();

    VehicleList& operator+=(const Vehicle& veh);
    VehicleList& operator-=(const Registration& reg);

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& vehlist);

    std::strong_ordering operator<=>(const VehicleList& other) const;
    bool operator==(const VehicleList& other) const;

    unsigned operator()(const char* cityCode) const;
    explicit operator bool() const;
    Vehicle* operator[](unsigned index);
    const Vehicle* operator[](unsigned index) const;

    bool isFreeSlot(unsigned pos) const;
    bool isEmpty() const;
    unsigned capacity() const;
    unsigned size() const;
    Vehicle* find(const Registration& reg) const;

};
