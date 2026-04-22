// #pragma once
// #include "Vehicle.h"
// class VehicleList {
//     Vehicle** vehicles;
//     size_t size;
//     size_t capacity;
//     void resize();
//     public:
//     VehicleList()=default;
//     VehicleList(size_t capacity_);
//     void operator+=( Vehicle& other);
//     void operator-=( Registration& reg);
//     ~VehicleList();
//
//     size_t operator()(const char* cod)const;
//
//     explicit operator bool() const;
//
//     Vehicle& operator[](size_t i);
//    const Vehicle& operator[](size_t i)const;
//     bool isFreeSlot(size_t pos)const;
//     bool isEmpty()const;
//     size_t getCapacity()const;
//     size_t getSize()const;
//     Vehicle* find(Registration& reg)const;
//
//     friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
// };
// std::ostream& operator<<(std::ostream& os, const VehicleList& list);



#pragma once
#include "Vehicle.h"
#include <iostream>

class VehicleList {
private:
    Vehicle** vehicles;
    size_t size_;
    size_t capacity_;
    void copyFrom(const VehicleList& other);
    void free();
    void resize();
    int findByRegistration(const Registration& reg) const;

public:
    VehicleList();
    VehicleList(size_t capacity = 8);
    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);
    ~VehicleList();
    VehicleList& operator+=(const Vehicle& vehicle);
    VehicleList& operator-=(const Registration& reg);
    Vehicle* find(const Registration& reg);
    size_t operator()(const char* code) const;
    Vehicle* operator[](size_t index);
    const Vehicle* operator[](size_t index) const;
    bool isFreeSlot(size_t pos) const;
    bool isEmpty() const;
    size_t size() const;
    size_t capacity() const;
    explicit operator bool() const;
    bool operator<(const VehicleList& other) const;
    bool operator>(const VehicleList& other) const;

    friend std::ostream& operator<<(std::ostream& os, const VehicleList& list);
};
std::ostream& operator<<(std::ostream& os, const VehicleList& list);