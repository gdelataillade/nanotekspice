/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(std::string name, std::string type)
: nts::IComponent(), _name(name), _type(type)  {}

nts::Tristate Component::compute(std::size_t pin) { return nts::UNDEFINED; }

void Component::setLink(std::size_t pin, IComponent &other,
                        std::size_t otherPin) {
    Component *downcast = dynamic_cast<Component*>(&other);

    this->_pin.push_back(pin);
    this->_otherPin.push_back(otherPin);
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

std::string Component::getType() const
{
    return this->_type;
}

nts::Tristate Component::getOutput(std::size_t pin)
{
    return this->_outputs.find(pin)->second;
}

std::size_t Component::findIndex(std::size_t value)
{
    std::vector<std::size_t>::iterator it = std::find(this->_pin.begin(), this->_pin.end(), value);

    // TODO: error check value not found: if it == _pin.end()
    return std::distance(this->_pin.begin(), it);
}

nts::Tristate Component::gateNot(nts::Tristate &int1)
{
    if (int1)
        return nts::FALSE;
    else if (!int1)
        return nts::TRUE;
    return nts::UNDEFINED;
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
