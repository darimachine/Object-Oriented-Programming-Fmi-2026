#pragma once
#include "Component.h"
#include <vector>
class Configuration
{
protected:
    std::vector<std::unique_ptr<Component>> components;
public:
    void insert(const std::unique_ptr<Component>& component);
    double price() const;
    size_t size() const;
    const std::unique_ptr<Component>& operator[](size_t index) const;
    std::unique_ptr<Component>& operator[](size_t index);
    std::ostream& operator<<(std::ostream& os) const;
};