#include "Configuration.h"
#include "Component.h"
#include <memory>
#include <iostream>

void Configuration::insert(const std::unique_ptr<Component>& component)
{
    components.push_back(std::move(component));
}

double Configuration::price() const
{
    double sum = 0;
    for (const auto& c : components) {
        sum += c->price();
    }
    return sum;
}

size_t Configuration::size() const {
    return components.size();
}

const std::unique_ptr<Component>& Configuration::operator[](size_t index) const {
    return components.at(index);
}

std::unique_ptr<Component>& Configuration::operator[](size_t index) {
    return components.at(index);
}

std::ostream &Configuration::operator<<(std::ostream &os) const
{
    os << "Configuration:\n ";
    for (const auto& c : components) {
        c->output(os);
    }

    os << "final price: " << price();
    return os;
}
