/*
** EPITECH PROJECT, 2019
** Untitled (Workspace)
** File description:
** Component
*/

#include "Component.hpp"

Component::Component(std::string name, std::string type)
: _name(name), _type(type), nts::IComponent()
{
}

nts::Tristate Component::compute(std::size_t pin)
{

}

void Component::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{

}