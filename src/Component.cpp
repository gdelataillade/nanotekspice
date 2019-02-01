/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(std::string name, std::string type)
    : nts::IComponent(), _name(name), _type(type)  {}

nts::Tristate Component::compute(std::size_t pin)
{
    for (int i = 0; i < (int)this->_links.size(); i++) {
        std::cout << _links[i].first << " ~ " << _links[i].second << " with " << _cmpt[i]->getName() << std::endl;
    }
    // Trouver les inputs (outputs du component precedent) et computex
    return nts::UNDEFINED;
}

void Component::setLink(std::size_t pin, IComponent &other,
                        std::size_t otherPin) {
    Component *downcast = dynamic_cast<Component*>(&other);

    this->_links.push_back(std::make_pair(pin, otherPin));
    this->_cmpt.push_back(downcast);

    // for (int i = 0; i < this->_links.size(); i++) {
    //     std::cout << _links[i].first << " ~ " << _links[i].second << " with " << _cmpt[i]->getName() << std::endl;
    // }
}

void Component::dump() const
{
    // delete component
    return;
}

std::string Component::getName() const
{
    return this->_name;
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
