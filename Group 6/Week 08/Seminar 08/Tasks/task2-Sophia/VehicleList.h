#pragma once
#include "Vehicle.h"

class VehicleList {
private:
    Vehicle** data;
    unsigned count;
    unsigned currentCapacity;

    void free();
    void copyFrom(const VehicleList& other);
    void resize();

public:
    VehicleList(unsigned initialCapacity);
    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);
    ~VehicleList();

    unsigned size() const;
    unsigned capacity() const;
    bool isEmpty() const;
    bool isFreeSlot(unsigned pos) const;

    VehicleList& operator+=(const Vehicle& v);
    VehicleList& operator-=(const Registration& r);
    
    unsigned operator()(const char* cityCode) const;
    operator bool() const;

    Vehicle* operator[](unsigned index);
    const Vehicle* operator[](unsigned index) const;

    Vehicle* find(const Registration& r);
    
    bool operator>(const VehicleList& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
};