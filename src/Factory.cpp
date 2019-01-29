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

Component* Factory::create4071(std::string const &name){
    return (new C4071(name));
}
