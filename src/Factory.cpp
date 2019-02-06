/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory() {
    this->chipsetConstructor["4071"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["input"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["output"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
}

Factory::~Factory() {}

Component *Factory::createComponent(std::string const &type, std::string const &name)
{
    if (this->chipsetConstructor.find(type) == this->chipsetConstructor.end())
        return nullptr;
    return this->chipsetConstructor[type](name); 
}

Component *Factory::create4071(std::string const &name){
    return new C4071(name);
}
