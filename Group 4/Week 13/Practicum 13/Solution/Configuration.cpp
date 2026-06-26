//
// Created by Boris Bozhilov on 5/28/2026.
//

#include "Configuration.h"
#include <memory>
#include <iostream>

size_t Configuration::size() const {
    return components.size();
}

double Configuration::getCost() const {

    double sum = 0;
    for (const auto& element : components) sum += element->price();

    return sum;
}

void Configuration::insert(const std::unique_ptr<Component> &component) {

    if (!component) throw std::invalid_argument("Can't insert an empty component");

    components.push_back(component->clone());
}

const Component& Configuration::operator[](const unsigned int index) const {

    if (components.empty()) throw std::logic_error("Collection of components is empty");
    if (index >= components.size()) throw std::out_of_range("Index is out of bounds");

    return *components.at(index);
}

std::ostream &operator<<(std::ostream &output, const Configuration &configuration) {

    const size_t componentsCount = configuration.size();

    for (size_t i = 0; i < componentsCount; i++) {

        configuration[i].output(output);
        output << std::endl;
    }

    std::print(output, "The total cost of the configuration is {:.2f}$", configuration.getCost());

    return output;
}
