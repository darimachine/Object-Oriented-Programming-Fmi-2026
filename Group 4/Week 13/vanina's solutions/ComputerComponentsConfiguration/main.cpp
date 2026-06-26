#include<iostream>

#include "ComponentFactory.hpp"
#include "Configuration.h"

int main() {
    auto component1 = ComponentFactory::createComponent();
    auto component2 = ComponentFactory::createComponent();
    auto component3 = ComponentFactory::createComponent();

    if (component1) {
        (*component1)->output(std::cout);
    }
    if (component2) {
        (*component2)->output(std::cout);
    }
    if (component3) {
        (*component3)->output(std::cout);
    }

    Configuration config;
    config.insert(*component1);
    config.insert(*component2);
    config.insert(*component3);

    std::cout << "######## new data ########" << std::endl;
    // std::cout << config.price();
    // config[0]->output(std::cout);
    // config[1]->output(std::cout);


    std::cout << config << std::endl;
    return 0;
}