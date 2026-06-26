#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Package.h"

class Warehouse {
    private:
        std::string warehouseName;
        size_t capacity;
        std::vector<std::unique_ptr<Package>> packages;
    public:
        std::string getWarehouseName() const;
        Warehouse(const std::string warehouseName, size_t capacity);
        Package* addPackage(const std::string trackingNumber, const std::string receiver, double weight, Priority priority);
        void removePackage(const std::string trackingNumber);
        bool operator[](const std::string trackingNumber);

        void transferTo(const std::string& trackingNumber, Warehouse& other);
        Package* heaviestPackage() const;
        int urgentPackages() const;
        double totalWeight() const;
        operator bool() const;
        bool operator()() const;

    };

    std::ostream& operator<<(std::ostream& os, const Warehouse& warehouse);