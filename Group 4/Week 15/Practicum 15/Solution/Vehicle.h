//
// Created by Boris Bozhilov on 5/30/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
#include <string>
#include <memory>

class Vehicle {

protected:
    std::string registration;

public:

    enum class Type {
        Car,
        Motorcycle,
        Train,
        Unknown
    };

    Vehicle() = default;
    explicit Vehicle(std::string registration);

    const std::string& getRegistration() const;

    [[nodiscard]] virtual std::unique_ptr<Vehicle> clone() const = 0;

    virtual void print(std::ostream& output);

    virtual ~Vehicle() = default;
};





#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_VEHICLE_H
