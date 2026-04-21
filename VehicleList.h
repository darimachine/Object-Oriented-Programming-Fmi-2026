#pragma once
#include "Vehicle.h"
class VehicleList
{
private:
    Vehicle** data;
    size_t currentSize;
    size_t currentCapacity;

    void copyFrom(const VehicleList& other);
    void free();

    void resize();
    int findIndexByReg(const Registration& reg) const;

public:
    explicit VehicleList(size_t capacity);
    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);
    ~VehicleList();

    VehicleList& operator+=(const Vehicle& vehicle);
    VehicleList& operator-=(const Registration& reg);
    bool operator==(const VehicleList& other) const;
    bool operator!=(const VehicleList& other) const;
    bool operator<(const VehicleList& other) const;
    bool operator>(const VehicleList& other) const;

    size_t operator()(const char* townCode) const;
    explicit operator bool() const;

    Vehicle* operator[](size_t index);
    const Vehicle* operator[](size_t index) const;

    bool isFreeSlot(size_t pos) const;
    bool isEmpty() const;
    size_t capacity() const;
    size_t size() const;

    Vehicle* find(const Registration& reg);
    const Vehicle* find(const Registration& reg) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
};

