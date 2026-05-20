#include "Configuration.h"

void Configuration::insert(std::unique_ptr<Component> &component) {
    components.push_back(std::move(component));
}

double Configuration::price() const {
    double result = 0;

    for (const auto& c : components) {
        result += c->price();
    }
    return result;
}

size_t Configuration::size() const {
    return components.size();
}

const std::unique_ptr<Component> & Configuration::operator[](size_t index) const {
    return components.at(index);
}

std::unique_ptr<Component> & Configuration::operator[](size_t index) {
    return components.at(index);
}

std::ostream& operator<<(std::ostream& os, const Configuration& c) {
    os << "Configuration:\n";
    size_t size = c.size();
    for (size_t i = 0; i < size; i++) {
        c[i]->output(os);
    }

    os << "final price: " << c.price();
    return os;
}
