/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory() {
    this->chipsetConstructor["4071"] = &Factory::create4071;
}

Factory::~Factory() {}

Component *Factory::create4071(std::string const &name) const noexcept {
    return dynamic_cast<Component*>(new C4071(name));
}

Component *Factory::createComponent(const std::string &type, const std::string &name)
{
    if (this->chipsetConstructor.find(type) == this->chipsetConstructor.end())
        return NULL;
    return this->chipsetConstructor[type](name); 
}