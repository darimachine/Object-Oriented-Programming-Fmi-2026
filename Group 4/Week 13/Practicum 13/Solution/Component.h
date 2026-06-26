//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENT_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENT_H

#include <string>
#include <memory>

class Component {

protected:

    std::string label;

public:

    Component() = default;
    explicit Component(std::string label) : label(std::move(label)){}

    [[nodiscard]] virtual double price() const = 0;
    virtual void output(std::ostream& output) const = 0;

    [[nodiscard]] virtual std::unique_ptr<Component> clone() const = 0;

    virtual ~Component() = default;
};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENT_H
