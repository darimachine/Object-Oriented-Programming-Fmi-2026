#pragma once
#include <string>
#include <memory>

class Component
{
protected:
    std::string label;
public:
    Component(const std::string& label);
    virtual double price() const = 0;
    virtual void output(std::ostream&) const = 0;
    virtual std::unique_ptr<Component> clone() const = 0;
    virtual ~Component() = default;
};