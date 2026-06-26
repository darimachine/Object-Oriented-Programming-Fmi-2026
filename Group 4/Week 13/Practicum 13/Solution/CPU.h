//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CPU_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CPU_H
#include "Component.h"


class CPU : public Component {

private:
    static constexpr double PRICE_PER_CORE = 19.99;

protected:
    unsigned short cores = 0;
    unsigned short clockSpeed = 0;

public:

    CPU();
    CPU(const unsigned short cores, const unsigned short clockSpeed);

    [[nodiscard]] double price() const override;
    void output(std::ostream &output) const override;

    [[nodiscard]] std::unique_ptr<Component> clone() const override;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_CPU_H
