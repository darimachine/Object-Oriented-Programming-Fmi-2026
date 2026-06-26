//
// Created by Boris Bozhilov on 5/28/2026.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENTFACTORY_H
#define OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENTFACTORY_H
#include <optional>

#include "Component.h"
#include "Utils.h"


class ComponentFactory {

private:
    static Utils::ComponentTypes askUserForType(std::ostream& output, std::istream& input);

public:
    static std::optional<std::unique_ptr<Component>> createComponentFromType(std::ostream& output, std::istream& input);

};



#endif //OBJECT_ORIENTED_PROGRAMMING_FMI_2026_COMPONENTFACTORY_H
