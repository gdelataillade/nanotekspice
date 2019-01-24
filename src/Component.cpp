/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(std::string name, std::string type)
    : _name(name), _type(type), nts::IComponent() {}

nts::Tristate Component::compute(std::size_t pin) {}

void Component::setLink(std::size_t pin, IComponent &other,
                        std::size_t otherPin) {
    Component *downcast = dynamic_cast<Component*>(&other);

    _links.insert({pin, otherPin});
    downcast->_links.insert({otherPin, pin});
}

nts::Tristate Component::gateAnd(nts::Tristate &int1, nts::Tristate &int2) {
    if (!int1 || !int2)
        return nts::FALSE;
    else if (int1 && int2)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate Component::gateOr(nts::Tristate &int1, nts::Tristate &int2) {
    if (int1 || int2)
        return nts::TRUE;
    else if (!int1 && !int2)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate Component::gateNor(nts::Tristate &int1, nts::Tristate &int2) {
    if (int1 || int2)
        return nts::FALSE;
    else if (!int1 && !int2)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate Component::gateXor(nts::Tristate &int1, nts::Tristate &int2) {
    if ((int1 && int2) || (!int1 && !int2))
        return nts::FALSE;
    else if (int1 || int2)
        return nts::TRUE;
    return nts::UNDEFINED;
}

nts::Tristate Component::gateXnor(nts::Tristate &int1, nts::Tristate &int2) {
    if ((int1 && int2) || (!int1 && !int2))
        return nts::TRUE;
    else if (int1 || int2)
        return nts::FALSE;
    return nts::UNDEFINED;
}

nts::Tristate Component::gateNand(nts::Tristate &int1, nts::Tristate &int2) {
    if (!int1 || !int2)
        return nts::TRUE;
    else if (int1 && int2)
        return nts::FALSE;
    return nts::UNDEFINED;
}
