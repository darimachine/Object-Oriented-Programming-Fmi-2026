//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_RAM_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_RAM_H
#include "Memory.h"

class RAM : public Memory {

private:
    static constexpr double PRICE_PER_GB = 49.99;

public:
    RAM() = default;
    explicit RAM(const unsigned short capacity);

    [[nodiscard]] double price() const override;

    [[nodiscard]] std::unique_ptr<Component> clone() const override;
};

#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_RAM_H
