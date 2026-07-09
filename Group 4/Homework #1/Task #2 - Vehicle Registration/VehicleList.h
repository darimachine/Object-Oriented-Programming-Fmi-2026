//
// Created by Boris Bozhilov on 4/18/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLELIST_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLELIST_H
#include "Vehicle.h"


class VehicleList {

private:

    static constexpr double ENLARGEMENT_RATE = 1.5;

    Vehicle** list = nullptr;
    unsigned int capacity = 0;
    unsigned int size = 0;

    // utility functions
    bool isValid() const;
    void copyListDataFromOther(const VehicleList& other);
    void moveListDataFromOther(VehicleList&& other);
    void freeListData();

    bool getFirstAvailableIndexInList(const Vehicle& candidateVehicle, unsigned int& availableIndex) const;
    void enlargeList(const unsigned int newCapacity);
    std::strong_ordering compareRegistrationOfFirstVehiclesToOther(const VehicleList& other) const;
    bool findIndexOfVehicleInList(const Registration& registration, unsigned int& indexInList) const;

public:

    bool checkForMatchingRegistrationVehicles() const;

    // rule of 5
    VehicleList();
    explicit VehicleList(const unsigned int capacity);

    VehicleList(const VehicleList& other);
    VehicleList& operator=(const VehicleList& other);

    VehicleList(VehicleList&& other) noexcept;
    VehicleList& operator=(VehicleList&& other) noexcept;

    // methods
    bool isFreeSlot(const unsigned int position) const;
    bool isEmpty() const;
    unsigned int getCapacity() const;
    unsigned int getSize() const;
    Vehicle* find(const Registration& registration) const;

    // operators
    VehicleList& operator+=(const Vehicle& other);
    VehicleList& operator-=(const Registration& vehicleRegistration);
    bool operator==(const VehicleList& other) const;
    std::strong_ordering operator<=>(const VehicleList& other) const;
    unsigned int operator()(const char* locationCode) const;
    explicit operator bool() const;
    Vehicle operator[](const unsigned int index) const;
    Vehicle& operator[](const unsigned int index);
    friend std::ostream& operator<<(std::ostream& output, const VehicleList& list);
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLELIST_H
