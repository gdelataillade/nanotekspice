/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory() {
    this->chipsetConstructor["4001"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4008"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4011"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4013"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4017"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4030"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4040"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4069"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4071"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4081"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4094"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4514"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["4801"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["2716"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["input"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["output"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["true"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["false"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["clock"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
    this->chipsetConstructor["terminal"] = std::bind(&Factory::create4071, this, std::placeholders::_1);
}

Factory::~Factory() {}

Component *Factory::createComponent(std::string const &type, std::string const &name)
{
    if (this->chipsetConstructor.find(type) != this->chipsetConstructor.end())
        return this->chipsetConstructor[type](name); 
    return nullptr;
}

Component *Factory::create4071(std::string const &name){
    return new C4071(name);
}
