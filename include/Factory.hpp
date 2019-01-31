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
    std::map<std::string, Component *(Factory::*)(std::string const &value) const noexcept> chipsetConstructor;
    Component *createComponent(const std::string &type, const std::string &name);

    Component* create4071(std::string const &name) const noexcept;
};

#endif /* !FACTORY_HPP_ */
