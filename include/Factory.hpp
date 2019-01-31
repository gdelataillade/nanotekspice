/*
** EPITECH PROJECT, 2019
** OOP_nanotekspice_2018
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <functional>

#include "C4071.hpp"

class Factory {
   public:
    Factory();
    ~Factory();

   protected:
   private:
    std::map<std::string, std::function<Component *(const std::string &)>> chipsetConstructor;
    Component *createComponent(std::string const &type, std::string const &name);

    Component* create4071(std::string const &name);
};

#endif /* !FACTORY_HPP_ */
