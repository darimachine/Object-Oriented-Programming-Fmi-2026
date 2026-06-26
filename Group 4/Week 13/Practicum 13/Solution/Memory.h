//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MEMORY_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MEMORY_H
#include "Component.h"


class Memory : public Component {

protected:
    unsigned short capacity = 0;

public:
    Memory();
    explicit Memory(std::string label, const unsigned short capacity);

    [[nodiscard]] double price() const override = 0;
    void output(std::ostream &output) const final;

    virtual ~Memory() = default;

    [[nodiscard]] std::unique_ptr<Component> clone() const override = 0;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_MEMORY_H
