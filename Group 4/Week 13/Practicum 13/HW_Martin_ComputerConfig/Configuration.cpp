#include "Configuration.h"

void Configuration::insert(const std::unique_ptr<Component>& component)
{
    if (component == nullptr)
    {
        return;
    }

    components.push_back(component->clone());
}

double Configuration::price() const
{
    double sum = 0;

    for (const auto& component : components)
    {
        sum += component->price();
    }

    return sum;
}

size_t Configuration::size() const
{
    return components.size();
}

const Component& Configuration::operator[](int index) const
{
    return *components.at(index);
}

std::ostream& operator<<(std::ostream& os, const Configuration& config)
{
    for (size_t i = 0; i < config.size(); ++i) 
    {
        config[i].output(os);
        os << "\n";
    }

    os << "-----------------------------------\n";
    os << "Total Configuration Price: " << config.price() << " EUR\n";

    return os;
}
