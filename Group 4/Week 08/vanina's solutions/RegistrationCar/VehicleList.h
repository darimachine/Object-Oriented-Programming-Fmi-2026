//
// Created by Vanina Laleva on 18.04.26.
//

#ifndef REGISTRATIONCAR_VEHICLELIST_H
#define REGISTRATIONCAR_VEHICLELIST_H

#include<iostream>
#include "Vehicle.h"

class VehicleList {
    Vehicle **vehicles{nullptr};
    size_t capacity = 0;
    size_t size = 0;

    //
    void copyFrom(const VehicleList &other);

    void free();

    void moveFrom(VehicleList &&other);

    void resize(size_t newCapacity);

public:
    explicit VehicleList(size_t capacity);

    VehicleList(const VehicleList &other);

    VehicleList &operator=(const VehicleList &other);

    VehicleList(VehicleList &&other) noexcept;

    VehicleList &operator=(VehicleList &&other) noexcept;

    ~VehicleList();

    //
    size_t getCapacity() const;

    size_t getSize() const;

    //
    const Vehicle *operator[](size_t index) const;

    Vehicle *operator[](size_t index);

    //
    bool isInSystem(const Vehicle &vehicle) const;

    VehicleList &operator+=(const Vehicle &vehicle);

    VehicleList &operator-=(const Vehicle &vehicle);

    VehicleList &operator-=(const Registration &other);

    //
    size_t operator()(const char *cityCode) const;

    operator bool() const;

    //
    bool isFreeSlot(size_t pos) const;

    bool isEmpty() const;

    Vehicle *find(const Registration &reg) const;
};

std::ostream &operator<<(std::ostream &os, const VehicleList &list);

std::strong_ordering operator<=>(const VehicleList &lhs, const VehicleList &rhs);

#endif //REGISTRATIONCAR_VEHICLELIST_H
