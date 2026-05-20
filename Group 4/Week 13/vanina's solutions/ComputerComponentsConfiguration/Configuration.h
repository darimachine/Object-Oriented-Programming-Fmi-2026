#ifndef COMPUTERCOMPONENTSCONFIGURATION_CONFIGURATION_H
#define COMPUTERCOMPONENTSCONFIGURATION_CONFIGURATION_H

#include <memory>
#include <vector>
#include<iostream>

#include "Component.h"


class Configuration {
    std::vector<std::unique_ptr<Component>> components;

public:
    void insert(std::unique_ptr<Component>& component);
    double price() const;
    size_t size() const;

    const std::unique_ptr<Component>& operator[](size_t index) const;
    std::unique_ptr<Component>& operator[](size_t index);
};

std::ostream& operator<<(std::ostream& os, const Configuration& c);


#endif //COMPUTERCOMPONENTSCONFIGURATION_CONFIGURATION_H