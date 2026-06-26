#include <iostream>

#include "ComponentFactory.h"
#include "Configuration.h"

int main() {


    auto c1 = ComponentFactory::createComponentFromType(std::cout, std::cin);
    auto c2 = ComponentFactory::createComponentFromType(std::cout, std::cin);
    auto c3 = ComponentFactory::createComponentFromType(std::cout, std::cin);
    auto c4 = ComponentFactory::createComponentFromType(std::cout, std::cin);

    Configuration configuration;

    configuration.insert(c1.value());
    configuration.insert(c2.value());
    configuration.insert(c3.value());
    configuration.insert(c4.value());

    std::cout << configuration;

    return 0;
}
