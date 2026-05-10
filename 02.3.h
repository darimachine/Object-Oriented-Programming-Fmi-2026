
#pragma once
#include "02.1.h"
#include "02.2.h"
#include <iostream>
#include <compare>

class VehicleList {
private:
    Vehicle** data;
    size_t    cap;
    size_t    currentSize;

    void free();
    void copyFrom(const VehicleList& other);
    void resize();

public:
    VehicleList(size_t initialCap = 4);
    ~VehicleList();
    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);

    VehicleList& operator+=(const Vehicle& v);
    VehicleList& operator-=(const Registration& reg);
    VehicleList& operator-=(const char* regStr);

    Vehicle* find(const Registration& reg) const;
    Vehicle* find(const char* reg) const;

    int operator()(const char* cityCode) const;

    explicit operator bool() const;

    bool   isEmpty() const;
    size_t size() const;
    size_t capacity() const;
    bool   isFreeSlot(size_t pos) const;

    Vehicle* operator[](size_t index);
    const Vehicle* operator[](size_t index) const;

    std::strong_ordering operator<=>(const VehicleList& other) const;
    bool operator==(const VehicleList& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
};