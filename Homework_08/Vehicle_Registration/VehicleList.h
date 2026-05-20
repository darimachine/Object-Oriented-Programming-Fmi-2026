#pragma once
#include "Vehicle.h"

class VehicleList {
    Vehicle** vehicles;
    int size_;
    int capacity_;

    void free();
    void copyFrom(const VehicleList& other);
    void moveFrom(VehicleList&& other) noexcept;
    void resize();

public:
    VehicleList(int capacity = 8);
    ~VehicleList();
    VehicleList(const VehicleList& other);
    VehicleList(VehicleList&& other) noexcept;
    VehicleList& operator=(const VehicleList& other);
    VehicleList& operator=(VehicleList&& other) noexcept;

    void operator+=(const Vehicle& v);
    void operator-=(const char* reg);
    void operator-=(const Registration& reg) { (*this) -= reg.getRegistration(); }

    Vehicle* find(const char* reg) const;
    Vehicle* find(const Registration& reg) const { return find(reg.getRegistration()); }

    int operator()(const char* code) const;
    explicit operator bool() const { return size_ > 0; }

    Vehicle* operator[](int index);
    const Vehicle* operator[](int index) const;

    bool isFreeSlot(int pos) const;
    bool isEmpty() const { return size_ == 0; }
    int size() const { return size_; }
    int capacity() const { return capacity_; }

    std::strong_ordering operator<=>(const VehicleList& other) const;
    bool operator==(const VehicleList& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& vl);
};