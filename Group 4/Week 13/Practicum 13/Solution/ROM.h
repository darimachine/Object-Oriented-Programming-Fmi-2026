//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ROM_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ROM_H
#include "Memory.h"

class ROM : public Memory {

private:
    static constexpr double PRICE_PER_GB = 4.99;

public:
    ROM() = default;
    explicit ROM(const unsigned short capacity);

    [[nodiscard]] double price() const override;

    [[nodiscard]] std::unique_ptr<Component> clone() const override;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_ROM_H
