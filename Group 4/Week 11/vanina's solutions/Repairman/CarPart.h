//
// Created by Vanina Laleva on 2.05.26.
//

#ifndef REPAIRMAN_CARPART_H
#define REPAIRMAN_CARPART_H

#include <string>
#include <iostream>

class CarPart {
    static unsigned idCounter;
    unsigned id;
    std::string name;
    std::string description;


public:
    CarPart(const std::string& name, const std::string& description);

    friend std::ostream& operator<<(std::ostream& os, const CarPart& part);
};


#endif //REPAIRMAN_CARPART_H