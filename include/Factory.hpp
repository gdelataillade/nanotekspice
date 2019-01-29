/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "C4071.hpp"

class Factory {
   public:
    Factory();
    ~Factory();

   protected:
   private:
    std::map<const std::string, Component (*)(std::string const &name)> chipsetConstructor;
    Component* create4071(std::string const &name);
};

#endif /* !FACTORY_HPP_ */
