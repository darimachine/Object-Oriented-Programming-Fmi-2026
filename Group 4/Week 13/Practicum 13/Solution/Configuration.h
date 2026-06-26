//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CONFIGURATION_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CONFIGURATION_H
#include <memory>
#include <vector>

#include "Component.h"


class Configuration {

private:
    std::vector<std::unique_ptr<Component>> components;

public:
    Configuration() = default;

    void insert(const std::unique_ptr<Component>& component);
    [[nodiscard]] double getCost() const;
    [[nodiscard]] size_t size() const;

    const Component& operator[](unsigned int index) const;
};

std::ostream& operator<<(std::ostream& output, const Configuration& configuration);

#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CONFIGURATION_H
