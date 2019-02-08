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
    std::map<std::size_t, std::size_t>::iterator itr;
    int tmp; // only for debug

    for (itr = _links.begin(); itr != _links.end(); itr++) {
        tmp = std::distance( _links.begin(), itr);
        // std::cout << itr->first << " ~ " << itr->second << " with " << _cmpt[tmp]->getName() << std::endl;
    }
    // Trouver les inputs (outputs du component precedent) et compute
    return nts::UNDEFINED;
}

void Component::setLink(std::size_t pin, IComponent &other,
                        std::size_t otherPin) {
    Component *downcast = dynamic_cast<Component*>(&other);

    this->_links.insert(std::pair<std::size_t, std::size_t>(pin, otherPin));
    this->_cmpt.push_back(downcast);
}

void Component::setOutputs(nts::Tristate state)
{
    this->_outputs.insert(std::pair<std::size_t, nts::Tristate>(1, state));
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

nts::Tristate Component::getOutput(std::size_t pin)
{
    return this->_outputs.find(pin)->second;
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
