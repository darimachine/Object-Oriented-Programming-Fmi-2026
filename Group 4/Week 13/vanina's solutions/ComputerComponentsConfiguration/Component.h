#ifndef COMPUTERCOMPONENTSCONFIGURATION_COMPONENT_H
#define COMPUTERCOMPONENTSCONFIGURATION_COMPONENT_H

#include<string>
#include<memory>

class Component {
protected:
    std::string label;

public:
    Component(const std::string& label);

    virtual double price() const = 0;
    virtual void output(std::ostream& os) const = 0;

    virtual ~Component() = default;

    virtual std::unique_ptr<Component> clone() const = 0;

};

#endif //COMPUTERCOMPONENTSCONFIGURATION_COMPONENT_H
